#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);

int main(void)
{
	size_t	len = 5;
	int		c = 65;
	char	my_b[6] = "";
	char	or_b[6] = "";

	ft_memset((void *)my_b, c, len);
	memset((void *)or_b, c, len);
	printf("mine: %s\n", my_b);
	printf("orgn: %s\n", or_b);
	return (0);
}
