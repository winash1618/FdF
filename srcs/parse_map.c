#include "fdf.h"

static void get_new_lst(t_dlist **nlst, char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_dlstadd_back(nlst, ft_dlstnew(map[i]));
		i++;
	}
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

void print_map(t_dlist *head)
{
	while (head)
	{
		t_dlist *tmp = head;
		while (tmp)
		{
			printf("%s ", tmp->content);
			tmp = tmp->next;
		}
		printf("\n");
		head = head->down;
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
	*head = olst;
	while (get_next_line(fd, &line) > 0)
	{
		nlst = NULL;
		get_new_lst(&nlst, ft_split(line, ' '));
		create_down_lst(&olst, nlst);
		olst = nlst;
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
	print_map(head);
	return (head);
}