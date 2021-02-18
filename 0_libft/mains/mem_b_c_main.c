#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../libft/libft.h"

int main(void)
{
	int		len = 12;
	void	*my_b;
	void	*or_b;
	void	*my_d;
	void	*or_d;
	void	*or_res;
	void	*my_res;
	int		*or_arr;
	int		*my_arr;

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
	or_res = memccpy(or_d, or_b + 6, -1, 6);
	my_res = ft_memccpy(my_d, my_b + 6, -1, 6);
	printf("1 - orgn: dst: %s  res ptr: %s\n", (char *)or_d, (char *)or_res);
	printf("    mine: dst: %s  res ptr: %s\n", (char *)my_d, (char *)my_res);
	or_res = memccpy(or_d, or_b + 6, 126, 6);
	my_res = ft_memccpy(my_d, my_b + 6, 126, 6);
	printf("2 - orgn: dst: %s  res ptr: %s\n", (char *)or_d, (char *)or_res);
	printf("    mine: dst: %s  res ptr: %s\n", (char *)my_d, (char *)my_res);

	printf("\nMEMMOVE\n");
	memmove(or_d, or_b, len);
	printf("1 - orgn: %s\n", or_d);
	ft_memmove(my_d, my_b, len);
	printf("    mine: %s\n", my_d);
	memmove(or_d + 3, or_d, 6);
	printf("2 - orgn: %s\n", or_d);
	ft_memmove(my_d + 3, my_d, 6);
	printf("    mine: %s\n", my_d);

	printf("\nMEMCHR\n");
	memset(or_b + 5, 126, 2);
	memset(my_b + 5, 126, 2);
	or_res = memchr(or_b, 126, len);
	printf("1 - orgn: res ptr: %s\n", or_res);
	my_res = ft_memchr(my_b, 126, len);
	printf("    mine: res ptr: %s\n", my_res);
	or_res = memchr(or_b, 122, len);
	printf("2 - orgn: res ptr: %s\n", or_res);
	my_res = ft_memchr(my_b, 122, len);
	printf("    mine: res ptr: %s\n", my_res);

	printf("\nMEMCMP\n");
	printf("1 - orgn: %d\n", memcmp(or_d, or_b, len));
	printf("    mine: %d\n", ft_memcmp(my_d, my_b, len));
	printf("2 - orgn: %d\n", memcmp(or_d, my_d, len));
	printf("    mine: %d\n", ft_memcmp(or_d, my_d, len));
	memset(or_b, 66, 1);
	memset(my_b, 66, 1);
	printf("3 - orgn: %d\n", memcmp(or_d, or_b, 0));
	printf("    mine: %d\n", ft_memcmp(my_d, my_b, 0));
	bzero(or_d, len);
	bzero(my_d, len);
	printf("4 - orgn: %d\n", memcmp(or_d, or_b, len));
	printf("    mine: %d\n", ft_memcmp(my_d, my_b, len));
	printf("5 - orgn: %d\n", memcmp(or_b, or_d, len));
	printf("    mine: %d\n", ft_memcmp(my_b, my_d, len));
	printf("6 - orgn: %d\n", memcmp(or_d, my_d, len));
	printf("    mine: %d\n", ft_memcmp(or_d, my_d, len));
	printf("7 - orgn: %d\n", memcmp("abcdefghij", "abcdefgxyz", 7));
	printf("    mine: %d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
	printf("8 - orgn: %d\n", memcmp("atoms\0\0\0\0", "atoms\0abc", 8));
	printf("    mine: %d\n", ft_memcmp("atoms\0\0\0\0", "atoms\0abc", 8));
	printf("9 - orgn: %d\n", memcmp("\xff\0\0\xaa\0\xde\xffMACOSX\xff", "\xff\0\0\xaa\0\xde\x00MBS", 9));
	printf("    mine: %d\n", ft_memcmp("\xff\0\0\xaa\0\xde\xffMACOSX\xff", "\xff\0\0\xaa\0\xde\x00MBS", 9));

	printf("\nBZERO\n");
	ft_bzero(my_b, 6);
	bzero(or_b, 6);
	printf("orgn: %s %s\n", (char *)or_b, (char *)or_b + 5);
	printf("mine: %s %s\n", (char *)my_b, (char *)my_b + 5);

	free(my_b);
	free(or_b);
	free(my_d);
	free(or_d);

	printf("\nCALLOC\n");
	or_arr = (int *)calloc(4, sizeof(int));
	my_arr = (int *)calloc(4, sizeof(int));
	printf("orgn: %d %d\n", ((int *)or_arr)[0], ((int *)or_arr)[3]);
	printf("mine: %d %d\n", ((int *)my_arr)[0], ((int *)my_arr)[3]);
	free(or_arr);
	free(my_arr);

	printf("\nNULL PROTECTION\n");
	ft_memcpy(NULL, NULL, len);
	ft_memmove(NULL, NULL, len);
	printf("All good\n\n");
	
	return (0);
}
