/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:18:44 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/31 08:26:06 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_map(t_fdf *fdf)
{
	t_dlist *head;
	t_dlist *tmp;

	head = fdf->map;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			if (tmp->next)
				draw_line(fdf, tmp, tmp->next);
			if (tmp->down)
				draw_line(fdf, tmp, tmp->down);
			tmp = tmp->next;
		}
		head = head->down;
	}
	// print_map(fdf->map);
}

void adjust_altitude(t_dlist *map, int alt)
{
	t_dlist *head;
	t_dlist *tmp;

	head = map;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			tmp->z += alt;
			tmp = tmp->next;
		}
		head = head->down;
	}
}

int key_press(int x, t_fdf *fdf)
{
	printf("key pressed: %d\n", x);
	if (x == 53)
		exit(0);
	if (x == 126)
		translate_map(fdf->map, 0, -10);
	if (x == 125)
		translate_map(fdf->map, 0, 10);
	if (x == 123)
		translate_map(fdf->map, -10, 0);
	if (x == 124)
		translate_map(fdf->map, 10, 0);
	if (x == 13)
		rotate_map_x(fdf->map, 0.1);
	if (x == 1)
		rotate_map_x(fdf->map, -0.1);
	if (x == 0)
		rotate_map_y(fdf->map, 0.1);
	if (x == 2)
		rotate_map_y(fdf->map, -0.1);
	if (x == 31)
		scale_map(fdf->map, 1.1);
	if (x == 34)
		scale_map(fdf->map, 0.9);
	if (x == 35)
		adjust_altitude(fdf->map, 1);
	if (x == 37)
		adjust_altitude(fdf->map, -1);
	mlx_destroy_image(fdf->mlx->mlx, fdf->img->img);
	fdf->img->img = mlx_new_image(fdf->mlx->mlx, IMG_WIDTH, IMG_HEIGHT);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->img->img, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		printf("usage: ./fdf <filename>");
		return (0);
	}
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	fdf->img = (t_img *)malloc(sizeof(t_img));
	fdf->map = parse_map(argv[1]);
	fdf->mlx->mlx = mlx_init();
	fdf->mlx->win = mlx_new_window(fdf->mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	fdf->img->img = mlx_new_image(fdf->mlx->mlx, IMG_WIDTH, IMG_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel,
			&fdf->img->line_length, &fdf->img->endian);
	init_map(fdf->map);
	draw_map(fdf);
	print_map(fdf->map);
	my_mlx_pixel_put(fdf->img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->img->img, 0, 0);
	mlx_hook(fdf->mlx->win, 2, 0, key_press, fdf);
	mlx_loop(fdf->mlx->mlx);
	return (0);
}