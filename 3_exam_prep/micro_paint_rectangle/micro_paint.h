#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct s_canvas
{
	int		width;
	int		height;
	char	bkg;
	char	**painting;
}				t_canvas;

typedef struct s_rectangle
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	c;
}				t_rectangle;

#endif
