#include "micro_paint.h"

int	parse_canvas_info(FILE *file, t_canvas *canvas)
{
	int	r;
	int	i;
	int	j;

	r = fscanf(file, "%d %d %c", &canvas->width, &canvas->height, &canvas->bkg);
	if (r != 3 || canvas->width <= 0 || canvas->width > 300 || canvas->height <= 0 ||
		canvas->height > 300)
		return (0);
	canvas->painting = (char **)malloc(sizeof(char *) * canvas->height);
	i = 0;
	while (i < canvas->height)
	{
		canvas->painting[i] = (char *)malloc(sizeof(char) * canvas->width);
		j = 0;
		while (j < canvas->width)
			canvas->painting[i][j++] = canvas->bkg;
		i++;
	}
	return (1);
}

int	is_in_rectangle(float x, float y, t_rectangle rectangle)
{
	float	thickness;

	thickness = 1.000000;
	if (x < rectangle.x || x > rectangle.x + rectangle.width || y < rectangle.y ||
		y > rectangle.y + rectangle.height)
		return (0);
	if (x < rectangle.x + thickness || x > rectangle.x + rectangle.width - thickness ||
		y < rectangle.y + thickness || y > rectangle.y + rectangle.height - thickness)
		return (BORDER);
	return (INSIDE);
}

void	paint_rectangle(t_canvas *canvas, t_rectangle rectangle)
{
	int	x;
	int	y;
	int	is_in;

	y = 0;
	while (y < canvas->height)
	{
		x = 0;
		while (x < canvas->width)
		{
			is_in = is_in_rectangle((float)x, (float)y, rectangle);
			if (is_in == BORDER || (is_in == INSIDE && rectangle.type == 'R'))
				canvas->painting[y][x] = rectangle.c;
			x++;
		}
		y++;
	}
}

int	parse_rectangle_info(FILE *file, t_canvas *canvas)
{
	int			r;
	t_rectangle	rectangle;

	r = fscanf(file, "\n%c %f %f %f %f %c", &rectangle.type, &rectangle.x, &rectangle.y,
		&rectangle.width, &rectangle.height, &rectangle.c);
	if (r == -1)
		return (-1); // EOF
	if (r != 6 || rectangle.width <= 0 || rectangle.height <= 0 ||
		(rectangle.type != 'r' && rectangle.type != 'R'))
		return (0);
	paint_rectangle(canvas, rectangle);
	return (1);
}

void	print_painting(t_canvas canvas)
{
	int	i;

	i = 0;
	while (i < canvas.height)
	{
		write(1, canvas.painting[i], canvas.width);
		write(1, "\n", 1);
		i++;
	}
}

void	clean_painting(t_canvas *canvas)
{
	int	i;

	i = 0;
	while (i < canvas->height)
		free(canvas->painting[i++]);
	free(canvas->painting);
}

int	main(int ac, char **av)
{
	FILE		*file;
	t_canvas	canvas;
	int			r;

	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if ((file = fopen(av[1], "r")))
	{
		if (parse_canvas_info(file, &canvas))
		{
			r = 1;
			while (r == 1)
			{
				r = parse_rectangle_info(file, &canvas);
				if (r == -1)
				{
					print_painting(canvas);
					clean_painting(&canvas);
					fclose(file);
					return (0);
				}
			}
			clean_painting(&canvas);
		}
		fclose(file);
	}
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}
