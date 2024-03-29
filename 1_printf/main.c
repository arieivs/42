#include "ft_printf.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>

int	main(void)
{
	int	orig;
	int	mine;
	/*int	a = 2;
	int	b = 3;
	short int sa = 2;
	short int sb = 3;
	long int	la = 2;
	long int	lb = 3;
	long long int lla = 2;
	long long int llb = 3;

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
	orig = printf("<% .d>\n", 0);
	mine = ft_printf("<% .d>\n", 0);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("<%0*.0d*0 0*%0*.10d>\n", -2, 0, 21, 1);
	mine = ft_printf("<%0*.0d*0 0*%0*.10d>\n", -2, 0, 21, 1);
	printf("orig: %d mine: %d\n\n", orig, mine);

	printf("\n** u **\n");
	orig = printf("%+uolare% -5uihu%0.3uolare\n", 21, 21, -54);
	mine = ft_printf("%+uolare% -5uihu%0.3uolare\n", 21, 21, -54);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%.uolare%+.1uihu\n", 0, 0);
	mine = ft_printf("%.uolare%+.1uihu\n", 0, 0);
	printf("orig: %d mine: %d\n\n", orig, mine);

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
	orig = printf("%#-03.2xolare%#-03.*Xihu\n", 1, 3, 1);
	mine = ft_printf("%#-03.2xolare%#-03.*Xihu\n", 1, 3, 1);
	printf("orig: %d mine: %d\n\n", orig, mine);

	printf("\n** c and %% **\n");
	orig = printf("hey%5cjude\n", 345);
	mine = ft_printf("hey%5cjude\n", 345);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("dont%05%make\n");
	mine = ft_printf("dont%05%make\n");
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("me%5ccry\n", 0);
	mine = ft_printf("me%5ccry\n", 0);
	printf("orig: %d mine: %d\n\n", orig, mine);

	printf("\n** s **\n");
	orig = printf("<%10.2s>\n", "hello");
	mine = ft_printf("<%10.2s>\n", "hello");
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("34<%-10s>\n", NULL);
	mine = ft_printf("34<%-10s>\n", NULL);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("35<%-9.1s>\n", NULL);
	mine = ft_printf("35<%-9.1s>\n", NULL);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("36<%.*s>\n", -2, NULL);
	mine = ft_printf("36<%.*s>\n", -2, NULL);
	printf("orig: %d mine: %d\n\n", orig, mine);

	printf("\n** p **\n");
	orig = printf("<%p>\n", 0);
	mine = ft_printf("<%p>\n", 0);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("hey%20pyou%-20pnow\n", &a, &a);
	mine = ft_printf("hey%20pyou%-20pnow\n", &a, &a);
	printf("orig: %d mine: %d\n\n", orig, mine);

	printf("\n** n  **\n");
	printf("hellooo%n suckerrrs\n", &a);
	ft_printf("hellooo%n suckerrrs\n", &b);
	printf("orig: %d mine: %d\n\n", a, b);*/

	printf("\n** f **\n");
	orig = printf("floating%.0faround%.fand%fagain\n", 44.5, 44.51, 42.0);
	mine = ft_printf("floating%.0faround%.fand%fagain\n", 44.5, 44.51, 42.0);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("floating% 012.faround%.2fand%.2fagain\n", 99.7358, 3.999, 9.999);
	mine = ft_printf("floating% 012.faround%.2fand%.2fagain\n", 99.7358, 3.999, 9.999);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("floating%.16faround\n", 0.01234567890123456789012345678901);
	mine = ft_printf("floating%.16faround\n", 0.01234567890123456789012345678901);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("long%fmax%fmin\n", LONG_MAX * 1.0, LONG_MIN * 1.0);
	mine = ft_printf("long%fmax%fmin\n", LONG_MAX * 1.0, LONG_MIN * 1.0);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("|%+f|%06f|%-6.1f|\n", INFINITY, -INFINITY, NAN);
	mine = ft_printf("|%+f|%06f|%-6f|\n", INFINITY, -INFINITY, NAN);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("wtf%.16f-.- %.16f\n", -0.000, 0.0);
	mine = ft_printf("wtf%.16f-.- %.16f\n", -0.000, 0.0);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("sharp%#.fbemol\n", 54.5);
	mine = ft_printf("sharp%#.fbemol\n", 54.5);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%.0f|%.0f|%.0f\n", -4.5, -2.5, -0.5);
	mine = ft_printf("%.0f|%.0f|%.0f\n", -4.5, -2.5, -0.5);
	printf("orig: %d mine: %d\n\n", orig, mine);

	/*printf("\n** SIZE **\n** hh **\n");
	orig = printf("hey%5hhdjude%.10hhd.\n", 255, -127);
	mine = ft_printf("hey%5hhdjude%.10hhd.\n", 255, -127);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("hey%5hhujude%.10hhu.\n", 255, -127);
	mine = ft_printf("hey%5hhujude%.10hhu.\n", 255, -127);
	printf("orig: %d mine: %d\n\n", orig, mine);
	printf("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890%hhnsuckerrrs\n", &a);
	ft_printf("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890%hhnsuckerrrs\n", &b);
	printf("orig: %d mine: %d\n\n", a, b);
	printf("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890%hhnsuckerrrs\n", &a);
	ft_printf("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890%hhnsuckerrrs\n", &b);
	printf("orig: %d mine: %d\n\n", a, b);

	printf("\n** h **\n");
	orig = printf("hey%0+2.2hdyo%*.*hd\n", (short int)42, 9, 6, (short int)5);
	mine = ft_printf("hey%0+2.2hdyo%*.*hd\n", (short int)42, 9, 6, (short int)5);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%+huolare% -5huihu\n", (short int)21, (short int)21);
	mine = ft_printf("%+huolare% -5huihu\n", 21, 21);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%#-03.2hxolare%#-03.*hXihu\n", (short int)1, 3, (short int)1);
	mine = ft_printf("%#-03.2hxolare%#-03.*hXihu\n", 1, 3, 1);
	printf("orig: %d mine: %d\n\n", orig, mine);
	printf("hellooo%hn suckerrrs\n", &sa);
	ft_printf("hellooo%hn suckerrrs\n", &sb);
	printf("orig: %hd mine: %hd\n\n", sa, sb);

	printf("\n** l **\n");
	orig = printf("hey%0+2.2ldyo%*.*ld\n", (long int)42, 9, 6, (long int)5);
	mine = ft_printf("hey%0+2.2ldyo%*.*ld\n", (long int)42, 9, 6, (long int)5);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%+luolare% -5luihu\n", (long int)21, (long int)21);
	mine = ft_printf("%+luolare% -5luihu\n", (long int)21, (long int)21);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%#-03.2lxolare%#-03.*lXihu\n", (long int)1, 3, (long int)1);
	mine = ft_printf("%#-03.2lxolare%#-03.*lXihu\n", (long int)1, 3, (long int)1);
	printf("orig: %d mine: %d\n\n", orig, mine);
	printf("hellooo%ln suckerrrs\n", &la);
	ft_printf("hellooo%ln suckerrrs\n", &lb);
	printf("orig: %ld mine: %ld\n\n", la, lb);
	orig = printf("<%ld>\n", LONG_MAX);
	mine = ft_printf("<%ld>\n", LONG_MAX);
	printf("orig: %d mine: %d\n\n", orig, mine);

	printf("\n** ll **\n");
	orig = printf("hey%0+2.2lldyo%*.*lld\n", (long long int)42, 9, 6, (long long int)5);
	mine = ft_printf("hey%0+2.2lldyo%*.*lld\n", (long long int)42, 9, 6, (long long int)5);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%+lluolare% -5lluihu\n", (long long int)21, (long long int)21);
	mine = ft_printf("%+lluolare% -5lluihu\n", (long long int)21, (long long int)21);
	printf("orig: %d mine: %d\n\n", orig, mine);
	orig = printf("%#-03.2llxolare%#-03.*llXihu\n", (long long int)1, 3, (long long int)1);
	mine = ft_printf("%#-03.2llxolare%#-03.*llXihu\n", (long long int)1, 3, (long long int)1);
	printf("orig: %d mine: %d\n\n", orig, mine);
	printf("hellooo%lln suckerrrs\n", &lla);
	ft_printf("hellooo%lln suckerrrs\n", &llb);
	printf("orig: %lld mine: %lld\n\n", lla, llb);
	orig = printf("<%lld>\n", LONG_MAX + 1);
	mine = ft_printf("<%lld>\n", LONG_MAX + 1);
	printf("orig: %d mine: %d\n\n", orig, mine);*/
	return (0);
}
