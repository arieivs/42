#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	c = 'c';
	char	s[] = "To be or not to be";
	int		x = 453910;
	int		y = -2147483648;

	if (ac != 2)
	{
		printf("Please give one filename as argument\n");
		return (0);
	}
	fd = open(av[1], O_WRONLY);
	if (fd == -1)
	{
		write(2, "Cannot open file.\n", 18);
		return (-1);
	}
	write(fd, "PUTS\n", 6);	
	ft_putchar_fd(c, fd);
	write(fd, "   ", 3);
	ft_putstr_fd(s, fd);
	write(fd, "   ", 3);
	ft_putendl_fd(s, fd);
	ft_putnbr_fd(x, fd);
	write(fd, "   ", 3);
	ft_putnbr_fd(y, fd);
	write(fd, "\n", 1);
	printf("cat file_name should print the following:\n");
	printf("PUTS\n%c   %s   %s\n%d   %d\n", c, s, s, x, y);
	if (close(fd) == -1)
	{
		write(2, "Cannot close file.\n", 19);
		return (-1);
	}
	return (0);
}
