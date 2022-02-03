#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

/*
 * FILE data type:
 * defined in stdio.h, system dependent
 * https://www.geeksforgeeks.org/data-type-file-c/
 * file descriptor: short	_file
 */

typedef struct s_circle {
	char	type;
	float	x;
	float	y;
	float	r;
	char	c;
}				t_circle;

typedef struct s_canvas {
	int			width;
	int			height;
	char		bkg;
	char		**painting;
}				t_canvas;

// might have to change this

#endif
