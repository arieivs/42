#include <unistd.h>

char	**ft_split(char *str, char *charset);

int	main(void)
{
	char str[] = " Hey there, I would like to ask you a question,,,";
	char charset[] = ", ";
	char **strs;
	int i;
	int j;

	strs = ft_split(str, charset);
	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			write(1, &strs[i][j], 1);
			j++;
		}
		write(1, "_\n", 2);
		i++;
	}
	return (0);
}
