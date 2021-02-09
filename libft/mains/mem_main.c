#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

int main(void)
{
	char	my_b[6] = "";
	char	or_b[6] = "";
	char	my_a[] = "hello there!!";
	char	or_a[] = "hello there!!";

	printf("MEMSET\n");
	ft_memset((void *)my_b, 65, 5);
	memset((void *)or_b, 65, 5);
	printf("1 - mine: %s\n", my_b);
	printf("    orgn: %s\n", or_b);

	ft_memset((void *)my_a + 3, 64, 5);
	memset((void *)or_a + 3, 64, 5);
	printf("2 - mine: %s\n", my_a);
	printf("    orgn: %s\n\n", or_a);

	printf("BZERO\n");
	ft_bzero((void *)my_b, 6);
	bzero((void *)or_b, 6);
	printf("mine: %s\n", my_b);
	printf("orgn: %s\n\n", or_b);
	return (0);
}
