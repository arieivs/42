#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//int	a = 2;
	int	orig;
	int	mine;

	printf("\n** d **\n");
	orig = printf("you%.*dtoo\n", 0, 0);
	mine = ft_printf("you%.*dtoo\n", 0, 0);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("hey %0+2.2d yo %*.*d\n", 42, 10, 6, 5982);
	mine = ft_printf("hey %0+2.2d yo %*.*d\n", 42, 10, 6, 5982);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("hey %0*d\n", -7, -54);
	mine = ft_printf("hey %0*d\n", -7, -54);
	printf("orig: %d mine: %d\n\n", orig, mine);
	
	/*printf("\n** u **\n");
	orig = printf("%+uolare% -5uihu%0.3uolare\n", 21, 21, 1);
	mine = ft_printf("%+uolare% -5uihu%0.3uolare\n", 21, 21, 1);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%.uolare%+.1uihu\n", 0, 0);
	mine = ft_printf("%.uolare%+.1uihu\n", 0, 0);
	printf("orig: %d mine: %d\n\n", orig, mine);*/

	printf("\n** x and X **\n");
	orig = printf("0*%-*x*0 0*%0*X*0 \n", 21, 1021, 21, 1011);
	mine = ft_printf("0*%-*x*0 0*%0*X*0 \n", 21, 1021, 21, 1011);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%+xolare% -5Xihu\n", 21, 21);
	mine = ft_printf("%+xolare% -5Xihu\n", 21, 21);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("0*%#-*x*0 0*%#0*X*0 \n", 21, 1021, 21, 1011);
	mine = ft_printf("0*%#-*x*0 0*%#0*X*0 \n", 21, 1021, 21, 1011);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%#+xolare%# -5Xihu\n", 21, 21);
	mine = ft_printf("%#+xolare%# -5Xihu\n", 21, 21);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%#.xolare%#+.1Xihu\n", 0, 0);
	mine = ft_printf("%#.xolare%#+.1Xihu\n", 0, 0);
	printf("orig: %d mine: %d\n\n", orig, mine);

	/*printf("\n** c **\n");
	orig = printf("hey%5cyou\n", 345);
	mine = ft_printf("hey%5cyou\n", 345);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("hey%5cyou\n", 0);
	mine = ft_printf("hey%5cyou\n", 0);
	printf("orig: %d mine: %d\n\n", orig, mine);

	printf("\n** s **\n");
	orig = printf("<%10.2s>\n", "hello");
	mine = ft_printf("<%10.2s>\n", "hello");
	printf("orig: %d mine: %d\n\n", orig, mine);
	printf("34<%-10s>\n", NULL);
	ft_printf("34<%-10s>\n", NULL);
	printf("orig: %d mine: %d\n\n", orig, mine);
	printf("35<%-9.1s>\n", NULL);
	ft_printf("35<%-9.1s>\n", NULL);
	printf("orig: %d mine: %d\n\n", orig, mine);
	printf("36<%.*s>\n", -2, NULL);
	ft_printf("36<%.*s>\n", -2, NULL);
	printf("orig: %d mine: %d\n\n", orig, mine);

	printf("\n** p **\n");
	printf("testing %p\n", &a);*/
	return (0);
}
