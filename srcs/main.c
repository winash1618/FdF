/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:18:44 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/30 07:55:40 by mkaruvan         ###   ########.fr       */
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
	// draw_line(fdf, 100, 10, 200, 1000, 0x00FF0000);
	init_map(fdf->map);
	scale_map(fdf->map, 7);
	// rotate_map_z(fdf->map, 45, 45, 0);
	rotate_map_x(fdf->map, 35, 45, 0);
	rotate_map_y(fdf->map, 45, 45, 0);
	translate_map(fdf->map, 300, 300);
	draw_map(fdf);
	print_map(fdf->map);
	my_mlx_pixel_put(fdf->img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->img->img, 0, 0);
	mlx_loop(fdf->mlx->mlx);
	return (0);
}