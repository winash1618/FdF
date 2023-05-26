#include "fdf.h"

int main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_dlist	*map;

	if (argc != 2)
	{
		printf("usage: ./fdf <filename>");
		return (0);
	}
	map = parse_map(argv[1]);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	// fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, "fdf");

	// mlx_loop(fdf->mlx);
	return (0);
}