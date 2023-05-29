/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:18:44 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/29 06:59:21 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_fdf *fdf, int x0, int y0, int x1, int y1, int c)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int d = 2 * dy - dx;
	int y = y0;
	int x = x0;
	while (x < x1)
	{
		my_mlx_pixel_put(fdf->img, x, y, c);
		if (d > 0)
		{
			y++;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
		x++;
	}
}

void draw_line_y(t_fdf *fdf, int x0, int y0, int x1, int y1, int c)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int d = 2 * dx - dy;
	int y = y0;
	int x = x0;
	while (y < y1)
	{
		my_mlx_pixel_put(fdf->img, x, y, c);
		if (d > 0)
		{
			x++;
			d = d + 2 * dy;
		}
		d = d - 2 * dx;
		y++;
	}
}

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
				draw_line(fdf, tmp->x, tmp->y, tmp->next->x, tmp->next->y, (tmp->c * tmp->z) ? 0xFF00000 : 0xFFFFFF);
			if (tmp->down)
				draw_line_y(fdf, tmp->x, tmp->y, tmp->down->x, tmp->down->y, (tmp->c * tmp->z) ? 0xFF00000 : 0xFFFFFF);
			tmp = tmp->next;
		}
		head = head->down;
	}
}

void init_map(t_dlist *map)
{
	t_dlist *head;
	t_dlist *tmp;
	int i;
	int j;

	head = map;
	i = 0;
	while (head)
	{
		j = 0;
		tmp = head;
		while (tmp)
		{
			tmp->x = i;
			tmp->y = j;
			tmp = tmp->down;
			j++;
		}
		head = head->next;
		i++;
	}
}

void scale_map(t_dlist *map, int scale)
{
	t_dlist *head;
	t_dlist *tmp;

	head = map;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			tmp->x *= scale;
			tmp->y *= scale;
			tmp = tmp->next;
		}
		head = head->down;
	}
}

void translate_map(t_dlist *map, int x, int y)
{
	t_dlist *head;
	t_dlist *tmp;

	head = map;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			tmp->x += x;
			tmp->y += y;
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
	draw_line(fdf, 100, 100, 1000, 1000, 0x00FF0000);
	// init_map(fdf->map);
	// scale_map(fdf->map, 20);
	// translate_map(fdf->map, 100, 100);
	// draw_map(fdf);
	// print_map(fdf->map);
	my_mlx_pixel_put(fdf->img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->img->img, 0, 0);
	mlx_loop(fdf->mlx->mlx);
	return (0);
}