#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	int size = 4;
	char *strs[] = {"hello", "my", "dearest", "world"};
	char *sep = "...";
	char *str;

	str = ft_strjoin(size, strs, sep);
	printf("%s\n", str);
	return (0);
}
