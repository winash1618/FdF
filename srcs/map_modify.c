/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:12:54 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/29 15:34:23 by mkaruvan         ###   ########.fr       */
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

void rotate_map(t_dlist *map, double x, double y, double z)
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
			tmp->x = x1 * cos(y) * cos(z) + y1 * (cos(z) * sin(x) * sin(y) - cos(x) * sin(z)) + z1 * (cos(x) * cos(z) * sin(y) + sin(x) * sin(z));
			tmp->y = x1 * cos(y) * sin(z) + y1 * (cos(x) * cos(z) + sin(x) * sin(y) * sin(z)) + z1 * (-cos(z) * sin(x) + cos(x) * sin(y) * sin(z));
			tmp->z = -x1 * sin(y) + y1 * cos(y) * sin(x) + z1 * cos(x) * cos(y);
			tmp = tmp->next;
		}
		head = head->down;
	}
}
