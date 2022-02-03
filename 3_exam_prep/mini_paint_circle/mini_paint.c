#include "mini_paint.h"

int	parse_paint_info(FILE *file, t_canvas *canvas)
{	
	int	r;
	int	i;
	int	j;

	r = fscanf(file, "%d %d %c", &canvas->width, &canvas->height, &canvas->bkg);
	if (r != 3 || canvas->width <= 0 || canvas->width > 300 ||
		canvas->height <= 0 || canvas->height > 300)
		return (0);
	canvas->painting = (char **)malloc(sizeof(char *) * canvas->height);
	i = 0;
	while (i < canvas->height)
	{
		canvas->painting[i] = (char *)malloc(sizeof(char) * canvas->width + 1);
		j = 0;
		while (j < canvas->width)
			canvas->painting[i][j++] = canvas->bkg;
		i++;
	}
	return (1);
}

void	paint_circle(t_canvas *canvas, t_circle circle)
{
	int		x;
	int		y;
	float	distance;

	y = 0;
	while (y < canvas->height)
	{
		x = 0;
		while (x < canvas->width)
		{
			distance = sqrtf((circle.x - x) * (circle.x - x) +
						(circle.y - y) * (circle.y - y));
			if ((circle.type == 'C' && distance <= circle.r) || (circle.type == 'c'
				&& distance > circle.r - 1.000000 && distance <= circle.r))
				canvas->painting[y][x] = circle.c;
			x++;
		}
		y++;
	}
}

int	parse_circle_info(FILE *file, t_canvas *canvas)
{
	(void)canvas;
	int			r;
	t_circle	circle;

	r = fscanf(file, "\n%c %f %f %f %c", &circle.type, &circle.x, &circle.y,
		&circle.r, &circle.c);
	if (r == -1)
		return (-1); // EOF
	if (r != 5 || circle.r <= 0 || (circle.type != 'c' && circle.type != 'C'))
		return (0); // Mismatch/Incorrect input
	paint_circle(canvas, circle);
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
		if (parse_paint_info(file, &canvas))
		{
			r = 1;
			while (r == 1)
			{
				r = parse_circle_info(file, &canvas);
				if (r == -1)
				{
					print_painting(canvas);
					clean_painting(&canvas);
					return (0); // Reached EOF without issues
				}
			}
			clean_painting(&canvas);
		}
	}
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}
