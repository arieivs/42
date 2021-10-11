#include "minitalk.h"
#include <stdio.h>

int	main(void)
{
	char	c = 97;
	int		ref = 128;
	char	*bin;
	int		i = 0;

	bin = (char*)malloc(sizeof(char)*(8 + 1));
	while (ref)
	{
		if (c & ref)
			bin[i] = '1';
		else
			bin[i] = '0';
		ft_putnbr_fd(ref, 1);
		ref = ref >> 1;
		i++;
	}
	bin[i] = 0;
	printf("%s\n", bin);
	return (0);
}
