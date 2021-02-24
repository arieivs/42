#include "get_next_line.h"
# include <fcntl.h>
#include <stdio.h>

int	get_next_line(int fd, char **line);

int	main(void)
{
	int		fd;
	char	*buff;

	fd = open("text_file", O_RDWR | O_CREAT);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (get_next_line(fd, &buff) > 0)
		write(1, buff, BUFFER_SIZE);
	write(1, "\n", 1);
	close(fd);
	free(buff);
	return (0);
}
