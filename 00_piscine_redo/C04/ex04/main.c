#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	int nb = 55041;
	//char base[] = "0123456789ABCDEF";
	char base[] = "poneyvif";

	ft_putnbr_base(nb, base);
	write(1, "\n", 1);
	return (0);
}
