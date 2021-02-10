#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);

int main(void)
{
	int		len = 12;
	void	*my_b;
	void	*or_b;
	void	*my_d;
	void	*or_d;
	void	*or_ccpy;
	void	*my_ccpy;

	my_b = (void *)malloc(sizeof(void) * (len + 1));
	or_b = (void *)malloc(sizeof(void) * (len + 1));
	my_d = (void *)malloc(sizeof(void) * (len + 1));
	or_d = (void *)malloc(sizeof(void) * (len + 1));

	printf("\nMEMSET\n");
	ft_memset(my_b, 65, len);
	memset(or_b, 65, len);
	printf("1 - orgn: %s\n", (char *)or_b);
	printf("    mine: %s\n", (char *)my_b);
	ft_memset(my_b + 3, 62, 6);
	memset(or_b + 3, 62, 6);
	printf("2 - orgn: %s\n", (char *)or_b);
	printf("    mine: %s\n", (char *)my_b);
	ft_memset(my_b + 9, -1, 6);
	memset(or_b + 9, -1, 6);
	printf("3 - orgn: %s\n", (char *)or_b);
	printf("    mine: %s\n", (char *)my_b);

	printf("\nMEMCPY\n");
	memcpy(or_d, or_b, 6);
	ft_memcpy(my_d, my_b, 6);
	printf("orgn: %s\n", (char *)or_d);
	printf("mine: %s\n", (char *)my_d);

	printf("\nMEMCCPY\n");
	or_ccpy = memccpy(or_d, or_b + 6, -1, 6);
	my_ccpy = ft_memccpy(my_d, my_b + 6, -1, 6);
	printf("1 - orgn: dst: %s  res ptr: %s\n", (char *)or_d, (char *)or_ccpy);
	printf("    mine: dst: %s  res ptr: %s\n", (char *)my_d, (char *)my_ccpy);
	or_ccpy = memccpy(or_d, or_b + 6, 126, 6);
	my_ccpy = ft_memccpy(my_d, my_b + 6, 126, 6);
	printf("2 - orgn: dst: %s  res ptr: %s\n", (char *)or_d, (char *)or_ccpy);
	printf("    mine: dst: %s  res ptr: %s\n", (char *)my_d, (char *)my_ccpy);

	printf("\nMEMMOVE\n");
	memmove(or_d, or_b, 12);
	printf("1 - orgn: %s\n", or_d);
	ft_memmove(my_d, my_b, 12);
	printf("    mine: %s\n", my_d);
	memmove(or_d + 3, or_d, 6);
	printf("2 - orgn: %s\n", or_d);
	ft_memmove(my_d + 3, my_d, 6);
	printf("    mine: %s\n", my_d);

	printf("\nBZERO\n");
	ft_bzero(my_b, 6);
	bzero(or_b, 6);
	printf("mine: %s\n", (char *)my_b);
	printf("orgn: %s\n\n", (char *)or_b);

	free(my_b);
	free(or_b);
	free(my_d);
	free(or_d);
	return (0);
}
