/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:13:03 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/29 08:13:04 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line_x(t_fdf *fdf, t_dlist *p0, t_dlist *p1)
{
	int dx = p1->x - p0->x;
	int dy = p1->y - p0->y;
	int d = 2 * dy - dx;
	int y = p0->y;
	int x = p0->x;
	while (x < p1->x)
	{
		my_mlx_pixel_put(fdf->img, x, y, p0->z > 0 ? 0x00FF00 : 0xFFFFFF);
		if (d > 0)
		{
			y++;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
		x++;
	}
}

void draw_line_y(t_fdf *fdf, t_dlist *p0, t_dlist *p1)
{
	int dx = p1->x - p0->x;
	int dy = p1->y - p0->y;
	int d = 2 * dx - dy;
	int y = p0->y;
	int x = p0->x;
	while (y < p1->y)
	{
		my_mlx_pixel_put(fdf->img, x, y, p0->z > 0 ? 0x00FF00 : 0xFFFFFF);
		if (d > 0)
		{
			x++;
			d = d + 2 * dy;
		}
		d = d - 2 * dx;
		y++;
	}
}