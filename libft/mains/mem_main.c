#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);

int main(void)
{
	size_t	len;
	int		c;
	void	*b;

	len = 5;
	c = 65;
	b = (void *)malloc(sizeof(void) * (len + 1));
	ft_memset(b, c, len);
	printf("%s\n", (char *)b);
	return (0);
}
