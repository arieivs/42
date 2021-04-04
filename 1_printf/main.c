#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	orig;
	int	mine;

	//ft_putstr("I like \'100\\ \a \b \f \r \t \v discounts\n");
	//printf("I like you %.*dtoo\n", 0, 0);
	//orig = printf("0*%-*x*0 0*%0*X*0 \n", 21, 1021, 21, 1011);
	orig = printf("<%10.5s>\n", "hey");
	//printf("<%10.s>\n", "hello");
	//iter_str("100%+ -05 -40%%discount % 0+-mm\n");
	//ft_printf("hey %0+2.2d yo %*.*d\n", 42, 10, 6, 5982);
	//ft_printf("hey %.0d", 0);
	//mine = ft_printf("0*%-*x*0 0*%0*X*0 \n", 21, 1021, 21, 1011);
	mine = ft_printf("<%10.5s>\n", "you");
	printf("\norig: %d mine: %d\n", orig, mine);
	//printf("hey%5cyou\n", 345);
	printf("34, %-3.s \n", NULL);
	ft_printf("34, %-3.s \n", NULL);
	printf("35, %-9.1s \n", NULL);
	ft_printf("35, %-9.1s \n", NULL);
	printf("36, %.*s \n", -2, NULL);
	ft_printf("36, %.*s \n", -2, NULL);
	return (0);
}
