#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"

int	main(void)
{
	int		len = 12;
	void	*my_b;
	void	*or_b;
	void	*my_d;
	void	*or_d;
	void	*or_res;
	void	*my_res;

	char	s1[] = "string";
	char	my_s2[20] = "";
	char	or_s2[20] = "";
	size_t	my_len;
	size_t	or_len;
	int		my_dif;
	int		or_dif;
	char	s3[20] = "";

	int		i;
	char	is[] = "a0[ ";
	char	bel = 7;
	char	to[] = "abRa C4D58rA";
	char	a[] = "  \n  0325 6";
	char	b[] = "  \t -870abc";
	char	c[] = "  ++89-";

	int		fd;
	char	ca = 'c';
	char	s[] = "To be or not to be";
	int		x = 453910;
	int		y = -2147483648;

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

	printf("\nBZERO\n");
	ft_bzero(my_b, 6);
	bzero(or_b, 6);
	printf("orgn: %s %s\n", (char *)or_b, (char *)or_b + 5);
	printf("mine: %s %s\n", (char *)my_b, (char *)my_b + 5);
	free(my_b);
	free(or_b);
	free(my_d);
	free(or_d);

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

	printf("\nSTRNCMP\n");
	or_dif = strncmp(s1, or_s2, 5);
	my_dif = ft_strncmp(s1, or_s2, 5);
	printf("1 - orgn: diff %d\n", or_dif);
	printf("    mine: diff %d\n", my_dif);
	or_dif = strncmp(s1, s3, 5);
	my_dif = ft_strncmp(s1, s3, 5);
	printf("2 - orgn: diff %d\n", or_dif);
	printf("    mine: diff %d\n", my_dif);
	or_dif = strncmp(s1, s3, 0);
	my_dif = ft_strncmp(s1, s3, 0);
	printf("3 - orgn: diff %d\n", or_dif);
	printf("    mine: diff %d\n", my_dif);

	printf("\nSTRCHR\n");
	printf("1 - orgn: res ptr: %s\n", strchr(or_s2, 105));
	printf("    mine: res ptr: %s\n", ft_strchr(or_s2, 105));
	printf("2 - orgn: res ptr: %s\n", strchr(s1, 0));
	printf("    mine: res ptr: %s\n", ft_strchr(s1, 0));
	printf("3 - orgn: res ptr: %s\n", strchr(s1, 104));
	printf("    mine: res ptr: %s\n", ft_strchr(s1, 104));

	printf("\nSTRRCHR\n");
	printf("1 - orgn: res ptr: %s\n", strrchr(or_s2, 105));
	printf("    mine: res ptr: %s\n", ft_strrchr(or_s2, 105));
	printf("2 - orgn: res ptr: %s\n", strrchr(s1, 0));
	printf("    mine: res ptr: %s\n", ft_strrchr(s1, 0));
	printf("3 - orgn: res ptr: %s\n", strrchr(s1, 104));
	printf("    mine: res ptr: %s\n", ft_strrchr(s1, 104));

	printf("\nSTRNSTR\n");
	printf("1 - orgn: res ptr: %s\n", strnstr(or_s2, "rst", 15));
	printf("    mine: res ptr: %s\n", ft_strnstr(or_s2, "rst", 15));
	printf("2 - orgn: res ptr: %s\n", strnstr(or_s2, "rst", 10));
	printf("    mine: res ptr: %s\n", ft_strnstr(or_s2, "rst", 10));
	printf("3 - orgn: res ptr: %s\n", strnstr(s1, "", 15));
	printf("    mine: res ptr: %s\n", ft_strnstr(s1, "", 15));
	printf("4 - orgn: res ptr: %s\n", strnstr(s1, "s", 0));
	printf("    mine: res ptr: %s\n", ft_strnstr(s1, "s", 0));
	printf("5 - orgn: res ptr: %s\n", strnstr("every", "yeah", 15));
	printf("    mine: res ptr: %s\n", ft_strnstr("every", "yeah", 15));

	i = 0;
	printf("\nIS\n");
	while (is[i])
	{
		printf("%d - orgnl: %c is ", i + 1, is[i]);
		if (isalpha(is[i]))
			printf("ALPHA ");
		if (isdigit(is[i]))
			printf("DIGIT ");
		if (isalnum(is[i]))
			printf("Alphanumeric ");
		if (isascii(is[i]))
			printf("ASCII ");
		printf("\n");

		printf("    my ft: %c is ", is[i]);
		if (ft_isalpha(is[i]))
			printf("ALPHA ");
		if (ft_isdigit(is[i]))
			printf("DIGIT ");
		if (ft_isalnum(is[i]))
			printf("Alphanumeric ");
		if (ft_isascii(is[i]))
			printf("ASCII ");
		printf("\n\n");
		i++;
	}
	printf("%d - orgnl: bel is ", i + 1);
	if (!isprint(bel))
		printf("non printable\n");
	printf("    my ft: bel is ");
	if (!ft_isprint(bel))
		printf("non printable\n");

	printf("\nTOUPPER\norgnl: ");
	i = 0;
	while (to[i])
	{
		printf("%c", toupper(to[i]));
		i++;
	}
	printf("\nmy ft: ");
	i = 0;
	while (to[i])
	{
		printf("%c", ft_toupper(to[i]));
		i++;
	}

	printf("\n\nTOLOWER\norgnl: ");
	i = 0;
	while (to[i])
	{
		printf("%c", tolower(to[i]));
		i++;
	}
	printf("\nmy ft: ");
	i = 0;
	while (to[i])
	{
		printf("%c", ft_tolower(to[i]));
		i++;
	}
	printf("\n");

	printf("\nATOI\n");
	printf("1 - orgn: %d\n", atoi(a));
	printf("    mine: %d\n", ft_atoi(a));
	printf("2 - orgn: %d\n", atoi(b));
	printf("    mine: %d\n", ft_atoi(b));
	printf("3 - orgn: %d\n", atoi(c));
	printf("    mine: %d\n", ft_atoi(c));

	printf("\nPUTS\n");
	fd = open("text_file", O_RDWR | O_CREAT);
	if (fd == -1)
	{
		write(2, "Cannot open file.\n", 18);
		return (-1);
	}
	write(fd, "PUTS\n", 6);	
	ft_putchar_fd(ca, fd);
	write(fd, "   ", 3);
	ft_putstr_fd(s, fd);
	write(fd, "   ", 3);
	ft_putendl_fd(s, fd);
	ft_putnbr_fd(x, fd);
	write(fd, "   ", 3);
	ft_putnbr_fd(y, fd);
	write(fd, "\n", 1);
	printf("\"cat text_file\" should print the following:\n");
	printf("PUTS\n%c   %s   %s\n%d   %d\n", ca, s, s, x, y);
	if (close(fd) == -1)
	{
		write(2, "Cannot close file.\n", 19);
		return (-1);
	}
	printf("\n");
	return (0);
}
