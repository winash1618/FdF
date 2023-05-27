#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "color.h"
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define IMG_WIDTH 1000
# define IMG_HEIGHT 1000
# define PI 3.14159265359

typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_mlx {
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_fdf
{
	t_mlx		*mlx;
	t_img		*img;
	t_dlist		*map;
}				t_fdf;

/********************************************************************/
/**************************** parse_map.c ***************************/
/********************************************************************/

t_dlist		*parse_map(char *file);

/********************************************************************/
/*************************** map_utils.c ****************************/
/********************************************************************/

void		free_map(char **map);

void		print_map(t_dlist *head);

int			get_color(char *str);

/********************************************************************/
/**************************** mlx_utils.c ***************************/
/********************************************************************/

void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif