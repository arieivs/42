#include <string.h>
#include <stdio.h>
#include "../libft.h"

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
	char	*my_s4;
	char	*or_s4;
	char	*s5;
	char	*s6;
	char	**strs;
	int		i;

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

	printf("\nSTRDUP\n");
	or_s4 = strdup("I am a string\n");
	my_s4 = ft_strdup("I am a string\n");
	printf("orgn: %s", or_s4);
	printf("mine: %s", my_s4);
	free(or_s4);
	free(my_s4);

	printf("\nSUBSTR\n");
	s5 = ft_substr("Hello darkness", 6, 4);
	printf("1 - from %s, should get dark => %s\n", "Hello darkness", s5);
	s5 = ft_substr("Hello darkness", 10, 6);
	printf("2 - from %s, should get ness => %s\n", "Hello darkness", s5);
	s5 = ft_substr("Hello darkness", 18, 6);
	printf("3 - from %s, should get nothing => %s\n", "Hello darkness", s5);

	printf("\nSTRJOIN\n");
	s5 = ft_strjoin("hello", " world");
	printf("1 - %s + %s = %s\n", "hello", " world", s5);
	s5 = ft_strjoin("", " world");
	printf("2 - %s + %s = %s\n", "empty", " world", s5);
	s5 = ft_strjoin("hello", "");
	printf("3 - %s + %s = %s\n", "hello", "empty", s5);
	s5 = ft_strjoin("", "");
	printf("4 - %s + %s = %s\n", "empty", "empty", s5);

	printf("\nSTRTRIM\n");
	s6 = "  \t   I am floating in space  \t  ";
	s5 = ft_strtrim(s6, " \t\n");
	printf("1 - orgn: \"%s\", trimmed: \"%s\"\n", s6, s5);
	s6 = "Too much space on the right \t ";
	s5 = ft_strtrim(s6, " \t\n");
	printf("2 - orgn: \"%s\", trimmed: \"%s\"\n", s6, s5);
	s6 = "   \t Too much space on the left";
	s5 = ft_strtrim(s6, " \t\n");
	printf("3 - orgn: \"%s\", trimmed: \"%s\"\n", s6, s5);
	s6 = "    Nothing to trim     ";
	s5 = ft_strtrim(s6, "");
	printf("4 - orgn: \"%s\", trimmed: \"%s\"\n", s6, s5);
	s6 = "  \t  \t";
	s5 = ft_strtrim(s6, " \t\n");
	printf("5 - orgn: \"%s\", trimmed: \"%s\"\n", s6, s5);

	printf("\nSPLIT\n");
	s6 = "     I am floating   in space   ";
	printf("1 - original: %s\n    splitted: ", s6);
	strs = ft_split(s6, ' ');
	i = 0;
	while(strs[i])
	{
		printf("%d-%s; ", i, strs[i]);
		i++;
	}
	s6 = "Too  much  space    in between";
	printf("\n2 - original: %s\n    splitted: ", s6);
	strs = ft_split(s6, ' ');
	i = 0;
	while(strs[i])
	{
		printf("%d-%s; ", i, strs[i]);
		i++;
	}
	s6 = "No separator at all";
	printf("\n3 - original: %s\n    splitted: ", s6);
	strs = ft_split(s6, (char)NULL);
	i = 0;
	while(strs[i])
	{
		printf("%d-%s; ", i, strs[i]);
		i++;
	}
	printf("\n");
	return (0);
}
