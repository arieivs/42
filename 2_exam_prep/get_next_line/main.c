#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int 	fd;
	char	*line;

	if (ac != 2)
	{
		printf("Provide the name of the file to open\n");
		return (0);
	}
	fd = open(av[1], O_RDWR | O_CREAT);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
