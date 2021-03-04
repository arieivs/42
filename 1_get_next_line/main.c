#include "get_next_line.h"
# include <fcntl.h>
#include <stdio.h>

int	get_next_line(int fd, char **line);

int	main(void)
{
	int		fd;
	char	*buff;
	int		ret;
	int		line;

	fd = open("text_file", O_RDWR | O_CREAT);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = 1;
	while ((ret = get_next_line(fd, &buff)) > 0)
		printf("%d - %s - returned %d\n", line++, buff, ret);
	close(fd);
	free(buff);
	return (0);
}
