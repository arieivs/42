#include "play_mlx.h"

void	my_pixel_put(t_img_info *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

void	draw_line(t_img_info *img, int xi, int yi, int xf, int yf, int color)
{
	float	length;
	float	dx;
	float	dy;
	float	x;
	float	y;

	// if start and end points are the same we'll have 0 / 0
	if (xi == xf && yi == yf)
	{
		my_pixel_put(img, xi, yi, color);
		return ;
	}
	// how much we need to travel in the x/y axis respectively
	dx = (float)(xf - xi);
	dy = (float)(yf - yi);
	// how much we need to travel in the line's direction
	length = sqrt((dy * dy) + (dx * dx));
	// step (how much we should increase x/y at a time)
	dx /= length;
	dy /= length;
	// starting points
	x = (float)xi;
	y = (float)yi;
	while (length > 0)
	{
		my_pixel_put(img, x, y, color);
		x += dx;
		y += dy;
		length--;
	}
}

void	draw_square(t_img_info *img, int xi, int yi, int size, int color)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		draw_line(img, xi, yi + i, xi + size, yi + i, color);
		i++;
	}
}

void	draw_circle(t_img_info *img, int x0, int y0, int r, int color)
{
	int	x;
	int	y;

	x = x0 - r;
	while (x <= x0 + r)
	{
		y = y0 + sqrt(r * r - (x - x0) * (x - x0));
		my_pixel_put(img, x, y, color);
		y = y0 - sqrt(r * r - (x - x0) * (x - x0));
		my_pixel_put(img, x, y, color);
		x++;
	}
	y = y0 - r;
	while (y <= y0 + r)
	{
		x = x0 + sqrt(r * r - (y - y0) * (y - y0));
		my_pixel_put(img, x, y, color);
		x = x0 - sqrt(r * r - (y - y0) * (y - y0));
		my_pixel_put(img, x, y, color);
		y++;
	}
}

