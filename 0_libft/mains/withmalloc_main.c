#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "../libft/libft.h"

static char	ft_alt_caps(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (toupper(c));
	return (tolower(c));
}

int main(void)
{
	int		*or_arr;
	int		*my_arr;
	char	*my_s4;
	char	*or_s4;
	char	*s5;
	char	*s6;
	char	**strs;
	int		i;
	char	(*pt_alt_caps)(unsigned int, char);

	printf("\nCALLOC\n");
	or_arr = (int *)calloc(4, sizeof(int));
	my_arr = (int *)calloc(4, sizeof(int));
	printf("orgn: %d %d\n", ((int *)or_arr)[0], ((int *)or_arr)[3]);
	printf("mine: %d %d\n", ((int *)my_arr)[0], ((int *)my_arr)[3]);
	free(or_arr);
	free(my_arr);

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
	strs = ft_split(s6, 0);
	i = 0;
	while(strs[i])
	{
		printf("%d-%s; ", i, strs[i]);
		i++;
	}
	s6 = "";
	printf("\n4 - original: %s\n    splitted: ", s6);
	strs = ft_split(s6, ' ');
	i = 0;
	while(strs[i])
	{
		printf("%d-%s; ", i, strs[i]);
		i++;
	}
	printf("\n");

	printf("\nITOA\n");
	printf("1 - i: %d, a: %s\n", 0, ft_itoa(0));
	printf("2 - i: %d, a: %s\n", 3510, ft_itoa(3510));
	printf("3 - i: %ld, a: %s\n\n", -2147483648, ft_itoa(-2147483648));

	printf("\nSTRMAPI\n");
	pt_alt_caps = &ft_alt_caps;
	s6 = "aLICe in WoNDerlAnD";
	s5 = ft_strmapi(s6, pt_alt_caps);
	printf("orgn: %s, alternating caps: %s\n", s6, s5);

	printf("\nEND\n");
	return (0);
}
