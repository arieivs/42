#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd3 = 0;
	int		fd4 = 0;
	char	*buff;
	int		ret = 1;
	int		line3 = 1;
	int		line4 = 1;

	if (ac == 2 || ac > 3)
	{
		printf("Please give me two files\n");
		return (0);
	}
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (ac == 1)
	{
		while ((ret = get_next_line(fd3, &buff)) > 0)
			printf("%d-%d: %s\n", ret, line3++, buff);
	}
	else
	{
		fd3 = open(av[1], O_RDWR);
		fd4 = open(av[2], O_RDWR);
		while (ret > 0)
		{
			ret = get_next_line(fd3, &buff);
			printf("%d-fd%d-%d: %s\n", ret, fd3, line3++, buff);
			ret = get_next_line(fd4, &buff);
			printf("%d-fd%d-%d: %s\n", ret, fd4, line4++, buff);
			//ret = get_next_line(fd5, &buff);
			//printf("%d-fd%d-%d: %s\n", ret, fd5, line5++, buff);
		}
	}
	if (ret == 0)
		printf("Reached EOF\n");
	if (ret == -1)
		printf("An Error occurred\n");
	close(fd3);
	close(fd4);
	free(buff);
	return (0);
}
