#include "mini_paint.h"

int	main(int ac, char **av)
{
	FILE	*file;

	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(av[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	printf("%d\n", file->_file);
	// call parsing function
	return (0);
}
