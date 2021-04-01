#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	printed;

	//ft_putstr("I like \'100\\ \a \b \f \r \t \v discounts\n");
	//printf("I like you %.*dtoo\n", 0, 0);
	printed = printf("you %- *.dtoo\n", 4, 0);
	//printf("printed %d\n", printed);
	//iter_str("100%+ -05 -40%%discount % 0+-mm\n");
	//ft_printf("hey %0+2.2d yo %*.*d\n", 42, 10, 6, 5982);
	//ft_printf("hey %.0d", 0);
	ft_printf("hey %- 4.dyaa ", 0);
	return (0);
}
