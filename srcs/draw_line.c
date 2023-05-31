/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:13:03 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/31 06:35:05 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line_low(t_fdf *fdf, t_dlist *p0, t_dlist *p1)
{
	int dx = p1->x - p0->x;
	int dy = p1->y - p0->y;
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int D = 2 * dy - dx;
	int y = p0->y;
	int x = p0->x;
	while ( x <= p1->x)
	{
		if (!(y >= 0 && y < IMG_HEIGHT && x >= 0 && x < IMG_WIDTH))
			break;
		my_mlx_pixel_put(fdf->img, x, y, p0->c);
		if (D > 0)
		{
			y = y + yi;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
		x++;
	}
}

void draw_line_high(t_fdf *fdf, t_dlist *p0, t_dlist *p1)
{
	int dx = p1->x - p0->x;
	int dy = p1->y - p0->y;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = 2 * dx - dy;
	int x = p0->x;
	int y = p0->y;
	while ( y <= p1->y)
	{
		if (!(y >= 0 && y < IMG_HEIGHT && x >= 0 && x < IMG_WIDTH))
			break;
		my_mlx_pixel_put(fdf->img, x, y, p0->c);
		if (D > 0)
		{
			x = x + xi;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
		y++;
	}
}

void draw_line(t_fdf *fdf, t_dlist *p0, t_dlist *p1)
{
	if (fabs(p1->y - p0->y) < fabs(p1->x - p0->x))
	{
		if (p0->x >= p1->x)
			draw_line_low(fdf, p1, p0);
		else
			draw_line_low(fdf, p0, p1);
	}
	else
	{
		if (p0->y >= p1->y)
			draw_line_high(fdf, p1, p0);
		else
			draw_line_high(fdf, p0, p1);
	}
}