#ifndef FDF_H
#define FDF_H
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define WIN_WIDTH 1000
#define WIN_HEIGHT 1000
#define PI 3.14159265359

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
}				t_fdf;

char **parse_map(char *file);

#endif