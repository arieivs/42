#include <stdlib.h>
#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int main()
{
	char *str = malloc(256);

	for(int i = 0; i < 256; i++)
	{
		str[i] = i + 1;
	}	
	ft_putstr_non_printable(str);
	printf("\n");
	
	free(str);
	return (0);
}
