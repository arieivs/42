#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);

int main(void)
{
	char	s1[] = "string";
	char	my_s2[20] = "";
	char	or_s2[20] = "";
	size_t	my_len;
	size_t	or_len;

	printf("\nSTRLEN\n");
	my_len = ft_strlen(s1);
	or_len = strlen(s1);
	printf("original length: %zu, my length: %zu\n", or_len, my_len);

	printf("\nSTRLCPY\n");
	my_len = ft_strlcpy(my_s2, s1, 0);
	or_len = strlcpy(or_s2, s1, 0);
	printf("1 - orgn: length %zu   dst %s\n", or_len, or_s2);
	printf("    mine: length %zu   dst %s\n", my_len, my_s2);	
	my_len = ft_strlcpy(my_s2, s1, 4);
	or_len = strlcpy(or_s2, s1, 4);
	printf("2 - orgn: length %zu   dst %s\n", or_len, or_s2);
	printf("    mine: length %zu   dst %s\n", my_len, my_s2);
	my_len = ft_strlcpy(my_s2, s1, 8);
	or_len = strlcpy(or_s2, s1, 8);
	printf("3 - orgn: length %zu   dst %s\n", or_len, or_s2);
	printf("    mine: length %zu   dst %s\n", my_len, my_s2);

	printf("\nSTRLCAT\n");
	my_len = ft_strlcat(my_s2, s1, 0);
	or_len = strlcat(or_s2, s1, 0);
	printf("1 - orgn: length %zu    dst %s\n", or_len, or_s2);
	printf("    mine: length %zu    dst %s\n", my_len, my_s2);	
	my_len = ft_strlcat(my_s2, s1, 4);
	or_len = strlcat(or_s2, s1, 4);
	printf("2 - orgn: length %zu   dst %s\n", or_len, or_s2);
	printf("    mine: length %zu   dst %s\n", my_len, my_s2);
	my_len = ft_strlcat(my_s2, s1, 10);
	or_len = strlcat(or_s2, s1, 10);
	printf("3 - orgn: length %zu   dst %s\n", or_len, or_s2);
	printf("    mine: length %zu   dst %s\n", my_len, my_s2);
	my_len = ft_strlcat(my_s2, s1, 18);
	or_len = strlcat(or_s2, s1, 18);
	printf("4 - orgn: length %zu   dst %s\n", or_len, or_s2);
	printf("    mine: length %zu   dst %s\n", my_len, my_s2);

	return (0);
}
