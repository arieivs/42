#include "mini_paint.h"

int	parse_paint_info(FILE *file, t_painting *painting)
{	
	int	r;
	int	i;
	int	j;

	r = fscanf(file, "%d %d %c", &painting->width, &painting->height, &painting->bkg);
	if (r != 3 || painting->width < 0 || painting->width >= 300 ||
		painting->height < 0 || painting->height >= 300)
		return (0);
	//printf("-%d-%d-%c-\n", painting->width, painting->height, painting->bkg);
	painting->canvas = (char **)malloc(sizeof(char *) * painting->height);
	i = 0;
	while (i < painting->height)
	{
		painting->canvas[i] = (char *)malloc(sizeof(char) * painting->width + 1);
		j = 0;
		while (j < painting->width)
			painting->canvas[i][j++] = painting->bkg;
		i++;
	}
	return (1);
}

void	paint_canvas(t_painting *painting, t_circle *circle)
{
	int		x;
	int		y;
	float	distance;

	y = 0;
	while (y < painting->height)
	{
		x = 0;
		while (x < painting->width)
		{
			distance = sqrtf((circle->x - x) * (circle->x - x) +
						(circle->y - y) * (circle->y - y));
			if (distance <= circle->r)
				painting->canvas[y][x] = circle->c;
			x++;
			// more complex, check empty circle stuff
			// TODO differentiate c from C
		}
		y++;
	}
}

int	parse_circle_info(FILE *file, t_painting *painting)
{
	(void)painting;
	int			r;
	t_circle	circle;

	r = fscanf(file, "\n%c %f %f %f %c", &circle.type, &circle.x, &circle.y,
		&circle.r, &circle.c);
	//printf("return %d\n", r);
	if (r == -1)
		return (-1); // EOF
	if (r != 5 || circle.r <= 0 || (circle.type != 'c' && circle.type != 'C'))
		return (0); // Mismatch/Incorrect input
	//printf("-%c-%f-%f-%f-%c-\n", circle.type, circle.x, circle.y, circle.r, circle.c);
	paint_canvas(painting, &circle);
	return (1);
}

void	print_canvas(t_painting painting)
{
	int	i;

	i = 0;
	while (i < painting.height)
	{
		write(1, painting.canvas[i], painting.width);
		write(1, "\n", 1);
		i++;
	}
}

void	clean_canvas(t_painting *painting)
{
	int	i;

	i = 0;
	while (i < painting->height)
		free(painting->canvas[i++]);
	free(painting->canvas);
}

int	main(int ac, char **av)
{
	FILE		*file;
	t_painting	painting;
	int			r;

	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if ((file = fopen(av[1], "r")))
	{
		//printf("file descriptor: %d\n", file->_file);
		if (parse_paint_info(file, &painting))
		{
			r = 1;
			while (r == 1)
			{
				r = parse_circle_info(file, &painting);
				if (r == -1)
				{
					print_canvas(painting);
					clean_canvas(&painting);
					return (0); // Reached EOF without issues
				}
			}
			clean_canvas(&painting);
		}
	}
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}
