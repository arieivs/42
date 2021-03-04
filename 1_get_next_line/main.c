#include "get_next_line.h"
# include <fcntl.h>
#include <stdio.h>

int	get_next_line(int fd, char **line);

int	main(int ac, char **av)
{
	int		fd;
	char	*buff;
	int		ret;
	int		line;

	if (ac > 2)
	{
		printf("Please give me one file at a time\n");
		return (0);
	}
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = 1;
	if (ac == 1)
	{
		fd = 1;
		while ((ret = get_next_line(fd, &buff)) > 0)
			printf("%d-%d: %s\n", ret, line++, buff);
	}
	else
	{
		fd = open(av[1], O_RDWR | O_CREAT);
		while ((ret = get_next_line(fd, &buff)) > 0)
			printf("%d-%d: %s\n", ret, line++, buff);
		printf("%d-%d: %s\n", ret, line++, buff);
	}
	if (ret == 0)
		printf("Reached EOF\n");
	if (ret == -1)
		printf("An Error occurred\n");
	close(fd);
	free(buff);
	return (0);
}
