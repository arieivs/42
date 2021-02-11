#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);

int main(void)
{
	char	s1[] = "string";
	char	my_s2[20] = "";
	char	or_s2[20] = "";
	size_t	my_len;
	size_t	or_len;
	int		my_res;
	int		or_res;
	char	s3[20] = "";

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

	printf("\nSTRCMP\n");
	or_res = strncmp(s1, or_s2, 5);
	my_res = ft_strncmp(s1, or_s2, 5);
	printf("1 - orgn: diff %d\n", or_res);
	printf("    mine: diff %d\n", my_res);
	or_res = strncmp(s1, s3, 5);
	my_res = ft_strncmp(s1, s3, 5);
	printf("2 - orgn: diff %d\n", or_res);
	printf("    mine: diff %d\n", my_res);
	or_res = strncmp(s1, s3, 0);
	my_res = ft_strncmp(s1, s3, 0);
	printf("3 - orgn: diff %d\n", or_res);
	printf("    mine: diff %d\n", my_res);

	printf("\nSTRCHR\n");
	printf("1 - orgn: res ptr: %s\n", strchr(s1, 105));
	printf("    mine: res ptr: %s\n", ft_strchr(s1, 105));
	printf("2 - orgn: res ptr: %s\n", strchr(s1, 0));
	printf("    mine: res ptr: %s\n", ft_strchr(s1, 0));
	printf("3 - orgn: res ptr: %s\n", strchr(s1, 104));
	printf("    mine: res ptr: %s\n", ft_strchr(s1, 104));

	return (0);
}
