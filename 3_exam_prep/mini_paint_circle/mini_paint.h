#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# define LINE 1
# define FILL 2

# include <unistd.h>
# include <stdio.h>

/*
 * FILE data type:
 * defined in stdio.h, system dependent
 * https://www.geeksforgeeks.org/data-type-file-c/
 * file descriptor: short	_file
 */

typedef struct s_circle {
	int		type;
	float	x;
	float	y;
	float	r;
	char	c;
}				t_circle;

typedef struct s_painting {
	int			width;
	int			height;
	char		bkg;
	t_circle	*circles;
}				t_painting;

// might have to change this

#endif
