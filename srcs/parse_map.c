/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:18:51 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/05/31 07:01:35 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void get_new_lst(t_dlist **nlst, char **map)
{
	int i;
	t_dlist *tmp;

	i = 0;
	while (map[i])
	{
		tmp = ft_dlstnew(ft_strdup(map[i]));
		tmp->c = get_color(map[i]);
		tmp->z = ft_atoi(map[i]);
		ft_dlstadd_back(nlst, tmp);
		i++;
	}
	free_map(map);
}

static void create_down_lst(t_dlist **olst, t_dlist *nlst)
{
	t_dlist *tmp;

	tmp = *olst;
	while (tmp)
	{
		tmp->down = nlst;
		tmp = tmp->next;
		nlst = nlst->next;
	}
}

static void read_map(int fd, t_dlist **head)
{
	char *line;
	t_dlist *olst;
	t_dlist *nlst;

	olst = NULL;
	if (get_next_line(fd, &line) > 0)
		get_new_lst(&olst, ft_split(line, ' '));
	free(line);
	*head = olst;
	while (get_next_line(fd, &line) > 0)
	{
		nlst = NULL;
		get_new_lst(&nlst, ft_split(line, ' '));
		create_down_lst(&olst, nlst);
		olst = nlst;
		free(line);
	}
}

t_dlist *parse_map(char *file)
{
	int fd;
	t_dlist *head;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read_map(fd, &head);
	return (head);
}