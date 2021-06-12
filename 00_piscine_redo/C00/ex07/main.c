#include <unistd.h>

void	ft_putnbr(int nb);

int	main(void)
{
	int nb = -2147483648;

	ft_putnbr(nb);
	write(1, "\n", 1);
	return(0);
}
