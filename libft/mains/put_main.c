#include "../libft.h"

int	main(void)
{
	char	c = 'c';
	char	s[] = "To be or not to be";

	write(1, "\nPUTS\n", 6);	
	ft_putchar_fd(c, 1);
	write(1, "   ", 3);
	ft_putstr_fd(s, 1);
	write(1, "   ", 3);
	ft_putendl_fd(s, 1);

	return (0);
}
