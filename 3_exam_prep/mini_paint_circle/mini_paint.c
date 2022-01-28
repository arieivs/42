#include "mini_paint.h"


int	parse_paint_info(FILE *file, t_painting *painting)
{	
	int	r;
	int	i;

	r = fscanf(file, "%d %d %c", &painting->width, &painting->height, &painting->bkg);
	if (r != 3 || painting->width < 0 || painting->width >= 300 ||
		painting->height < 0 || painting->height >= 300)
		return (0);
	//printf("-%d-%d-%c-\n", painting->width, painting->height, painting->bkg);
	painting->canvas = (char **)malloc(sizeof(char *) * painting->height);
	i = 0;
	while (i < painting->height)
		painting->canvas[i++] = (char *)malloc(sizeof(char) * painting->width + 1);
	return (1);
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
	//TODO paint canvas
	return (1);
}

void	clean_up(t_painting *painting)
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
					// time to paint to terminal
					clean_up(&painting);
					return (0); // Reached EOF without issues
				}
			}
			clean_up(&painting);
		}
	}
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}
