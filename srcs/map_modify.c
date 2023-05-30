/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:12:54 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/30 07:14:10 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void conversion(double *x, double *y, double *z)
{
	*x = *x * PI / 180;
	*y = *y * PI / 180;
	*z = *z * PI / 180;
}

void rotate_map_y(t_dlist *map, double x, double y, double z)
{
	t_dlist *head;
	t_dlist *tmp;
	double x1;
	double y1;
	double z1;
	conversion(&x, &y, &z);
	head = map;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			x1 = tmp->x;
			y1 = tmp->y;
			z1 = tmp->z;
			tmp->x = cos(x) * x1 + sin(x) * z1;
			tmp->y = y1;
			tmp->z = - sin(x) * x1 + cos(x) * z1;
			tmp = tmp->next;
		}
		head = head->down;
	}
}
void rotate_map_z(t_dlist *map, double x, double y, double z)
{
	t_dlist *head;
	t_dlist *tmp;
	double x1;
	double y1;
	double z1;
	conversion(&x, &y, &z);
	head = map;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			x1 = tmp->x;
			y1 = tmp->y;
			z1 = tmp->z;
			tmp->x = cos(x) * x1 + sin(x) * y1;
			tmp->y = - sin(x) * x1 + cos(x) * y1;
			tmp->z = z1;
			tmp = tmp->next;
		}
		head = head->down;
	}
}

void rotate_map_x(t_dlist *map, double x, double y, double z)
{
	t_dlist *head;
	t_dlist *tmp;
	double x1;
	double y1;
	double z1;
	conversion(&x, &y, &z);
	head = map;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			x1 = tmp->x;
			y1 = tmp->y;
			z1 = tmp->z;
			tmp->x = x1;
			tmp->y = cos(y) * y1 - sin(y) * z1;
			tmp->z = sin(y) * y1 + cos(y) * z1;
			tmp = tmp->next;
		}
		head = head->down;
	}
}
