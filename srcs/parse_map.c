#include "fdf.h"

char **parse_map(char *file)
{
	int fd;
	char *line;
	char **map;

	fd = open(file, O_RDONLY);
	map = NULL;
	if (fd < 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		fflush(stdout);
		map = ft_split(line, ' ');
	}
	return (map);
}