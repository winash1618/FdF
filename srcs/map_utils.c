/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:18:34 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/28 18:17:49 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_map(t_dlist *head)
{
	while (head)
	{
		t_dlist *tmp = head;
		while (tmp)
		{
			printf("[");
			printf(GREEN" %.1f,"ANSI_RESET, tmp->x);
			printf(BLUE" %.1f,"ANSI_RESET, tmp->y);
			if (tmp->z > 0)
				printf(RED" %.1f,"ANSI_RESET, tmp->z);
			else
				printf(GREEN" %.1f,"ANSI_RESET, tmp->z);
			printf(CYAN" 0x%X"ANSI_RESET, tmp->c);
			printf("] ");
			tmp = tmp->next;
		}
		printf("\n");
		printf("\n");
		printf("\n");
		head = head->down;
	}
}


void free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int get_color(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (ft_atoi_base(str + i + 3, 16));
		i++;
	}
	return (0xFFFFFF);
}