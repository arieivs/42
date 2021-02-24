#include "get_next_line.h"
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	buff[BUFFER_SIZE + 1];
	int		read_size;
	char	*next_line;

	fd = open("text_file", O_RDWR | O_CREAT);
	read_size = read(fd, buff, BUFFER_SIZE);
	buff[read_size] = 0;
	next_line = get_next_line(fd, buff);
	write(1, buff, read_size);
	return (0);
}
