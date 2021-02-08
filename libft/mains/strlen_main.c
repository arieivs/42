#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);

int main(void)
{
	char str[] = "string";
	size_t my_len;
	size_t or_len;

	my_len = ft_strlen(str);
	or_len = strlen(str);
	printf("original length: %zu, my length: %zu\n", or_len, my_len);
	return (0);
}
