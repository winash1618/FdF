/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:12:54 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/31 08:26:14 by mkaruvan         ###   ########.fr       */
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

// void move_center_to_origin(t_dlist *map, t_dlist *center)
// {
// 	int min_x;
// 	int min_y;

// 	min_x = center->x;
// 	min_y = center->y;
// 	t_dlist *head;
// 	t_dlist *tmp;

// 	head = map;
// 	while (head)
// 	{
// 		tmp = head;
// 		while (tmp)
// 		{
// 			tmp->x -= min_x;
// 			tmp->y -= min_y;
// 			tmp = tmp->next;
// 		}
// 		head = head->down;
// 	}
// }

// void move_origin_to_center(t_dlist *map, t_dlist *center)
// {
// 	int min_x;
// 	int min_y;

// 	min_x = center->x;
// 	min_y = center->y;
// 	t_dlist *head;
// 	t_dlist *tmp;
	
// 	head = map;
// 	while (head)
// 	{
// 		tmp = head;
// 		while (tmp)
// 		{
// 			tmp->x += min_x;
// 			tmp->y += min_y;
// 			tmp = tmp->next;
// 		}
// 		head = head->down;
// 	}
// }

// t_dlist *find_center(t_dlist *map)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	t_dlist *head;
// 	head = map;
// 	while (head)
// 	{
// 		x++;
// 		head = head->next;
// 	}
// 	head = map;
// 	while (head)
// 	{
// 		y++;
// 		head = head->down;
// 	}
// 	x /= 2;
// 	y /= 2;
// 	int i = 0;
// 	head = map;
// 	while (i < x)
// 	{
// 		head = head->next;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < y)
// 	{
// 		head = head->down;
// 		i++;
// 	}
// 	return (head);
// }

void rotate_map_x(t_dlist *map, double rot_x)
{
	t_dlist *head;
	t_dlist *tmp;
	double x1;
	double y1;
	double z1;
	
	head = map;
	// t_dlist *center = find_center(map);
	// move_center_to_origin(map, center);
	double a = cos(rot_x / 2);
	double b = sin(rot_x / 2);
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
	// move_origin_to_center(map, center);
}

void rotate_map_y(t_dlist *map, double rot_x)
{
	t_dlist *head;
	t_dlist *tmp;
	double x1;
	double y1;
	double z1;
	
	head = map;
	// t_dlist *center = find_center(map);
	// move_center_to_origin(map, center);
	double a = cos(rot_x / 2);
	double b = sin(rot_x / 2);
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
	// move_origin_to_center(map, center);
}