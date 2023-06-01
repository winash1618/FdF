/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:12:54 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/01 07:52:34 by mkaruvan         ###   ########.fr       */
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

void scale_map(t_dlist *map, double scale)
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
			// tmp->z *= scale;
			tmp = tmp->next;
		}
		head = head->down;
	}
}

void adjust_altitude(t_dlist *map, double height)
{
	t_dlist *head;
	t_dlist *tmp;

	head = map;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			tmp->z += height;
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

// void rotate_map_x(t_dlist *map, double rot_x)
// {
// 	t_dlist *head;
// 	t_dlist *tmp;
// 	double x1;
// 	double y1;
// 	double z1;
	
// 	head = map;
// 	while (head)
// 	{
// 		tmp = head;
// 		while (tmp)
// 		{
// 			x1 = tmp->x;
// 			y1 = tmp->y;
// 			z1 = tmp->z;
// 			tmp->x = x1;
// 			tmp->y = cos(rot_x) * y1 - sin(rot_x) * z1;
// 			tmp->z = sin(rot_x) * y1 + cos(rot_x) * z1;
// 			tmp = tmp->next;
// 		}
// 		head = head->down;
// 	}
// }

// void rotate_map_y(t_dlist *map, double rot_y)
// {
// 	t_dlist *head;
// 	t_dlist *tmp;
// 	double x1;
// 	double y1;
// 	double z1;
// 	head = map;
// 	while (head)
// 	{
// 		tmp = head;
// 		while (tmp)
// 		{
// 			x1 = tmp->x;
// 			y1 = tmp->y;
// 			z1 = tmp->z;
// 			tmp->x = cos(rot_y) * x1 + sin(rot_y) * z1;
// 			tmp->y = y1;
// 			tmp->z = - sin(rot_y) * x1 + cos(rot_y) * z1;
// 			tmp = tmp->next;
// 		}
// 		head = head->down;
// 	}
// }

void move_to_center(t_dlist *map, t_dlist head_old)
{
	t_dlist *head;
	t_dlist *tmp;
	double x;
	double y;
	double z;

	head = map;
	x = head->x - head_old.x;
	y = head->y - head_old.y;
	z = head->z - head_old.z;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			tmp->x = tmp->x - x;
			tmp->y = tmp->y - y;
			tmp->z = tmp->z - z;
			tmp = tmp->next;
		}
		head = head->down;
	}
}

void rotate_map_x(t_dlist *map, double rot_x)
{
	t_dlist *head;
	t_dlist *tmp;
	double x1;
	double y1;
	double z1;
	
	head = map;
	double a = cos(rot_x / 2);
	double b = sin(rot_x / 2);
	t_dlist head_old = *head;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			x1 = tmp->x;
			y1 = tmp->y;
			z1 = tmp->z;
			tmp->x = x1;
			tmp->y = (a * a - b * b) * y1 - (2 * a * b) * z1;
			tmp->z = (2 * a * b) * y1 + (a * a - b * b) * z1;
			tmp = tmp->next;
		}
		head = head->down;
	}
	move_to_center(map, head_old);
}

void rotate_map_y(t_dlist *map, double rot_y)
{
	t_dlist *head;
	t_dlist *tmp;
	double x1;
	double y1;
	double z1;
	
	head = map;
	double a = cos(rot_y / 2);
	double b = sin(rot_y / 2);
	t_dlist head_old = *head;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			x1 = tmp->x;
			y1 = tmp->y;
			z1 = tmp->z;
			tmp->x = (a * a - b * b) * x1 + (2 * a * b) * z1;
			tmp->y = y1;
			tmp->z = (-2 * a * b) * x1 + (a * a - b * b) * z1;
			tmp = tmp->next;
		}
		head = head->down;
	}
	move_to_center(map, head_old);
}

void rotate_map_z(t_dlist *map, double rot_z)
{
	t_dlist *head;
	t_dlist *tmp;
	double x1;
	double y1;
	double z1;
	
	head = map;
	double a = cos(rot_z / 2);
	double b = sin(rot_z / 2);
	t_dlist head_old = *head;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			x1 = tmp->x;
			y1 = tmp->y;
			z1 = tmp->z;
			tmp->x = (a * a - b * b) * x1 - (2 * a * b) * y1;
			tmp->y = (2 * a * b) * x1 + (a * a - b * b) * y1;
			tmp->z = z1;
			tmp = tmp->next;
		}
		head = head->down;
	}
	move_to_center(map, head_old);
}