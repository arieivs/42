#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a = 2;
	/*int	orig;
	int	mine;

	printf("\nd\n");
	orig = printf("you%.*dtoo\n", 0, 0);
	mine = ft_printf("you%.*dtoo\n", 0, 0);
	printf("\norig: %d mine: %d\n", orig, mine);
	orig = printf("hey %0+2.2d yo %*.*d\n", 42, 10, 6, 5982);
	mine = ft_printf("hey %0+2.2d yo %*.*d\n", 42, 10, 6, 5982);
	printf("\norig: %d mine: %d\n", orig, mine);
	
	printf("\nx and X\n");
	orig = printf("0*%-*x*0 0*%0*X*0 \n", 21, 1021, 21, 1011);
	mine = ft_printf("0*%-*x*0 0*%0*X*0 \n", 21, 1021, 21, 1011);
	printf("\norig: %d mine: %d\n", orig, mine);

	printf("\nc\n");
	orig = printf("hey%5cyou\n", 345);
	mine = ft_printf("hey%5cyou\n", 345);
	printf("\norig: %d mine: %d\n", orig, mine);
	orig = printf("hey%5cyou\n", 0);
	mine = ft_printf("hey%5cyou\n", 0);
	printf("\norig: %d mine: %d\n", orig, mine);

	printf("\ns\n");
	orig = printf("<%10.2s>\n", "hello");
	mine = ft_printf("<%10.2s>\n", "hello");
	printf("\norig: %d mine: %d\n", orig, mine);
	printf("34<%-10s>\n", NULL);
	ft_printf("34<%-10s>\n", NULL);
	printf("\norig: %d mine: %d\n", orig, mine);
	printf("35<%-9.1s>\n", NULL);
	ft_printf("35<%-9.1s>\n", NULL);
	printf("\norig: %d mine: %d\n", orig, mine);
	printf("36<%.*s>\n", -2, NULL);
	ft_printf("36<%.*s>\n", -2, NULL);
	printf("\norig: %d mine: %d\n", orig, mine);*/

	printf("\np\n");
	printf("testing %p\n", &a);
	return (0);
}
