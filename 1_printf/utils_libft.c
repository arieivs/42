#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnegnbr_fd(int n, int fd)
{
	if (n <= -10)
		ft_putnegnbr_fd(n / 10, fd);
	ft_putchar_fd(-(n % 10) + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnegnbr_fd(n, fd);
	}
	else
		ft_putnegnbr_fd(-n, fd);
}
