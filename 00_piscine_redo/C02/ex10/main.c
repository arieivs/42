#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char src[] = "hello";
	int dest_size = 6;
	char sup_dest[dest_size];
	char my_dest[dest_size];
	int sup_src_size;
	int my_src_size;

	sup_src_size = strlcpy(sup_dest, src, dest_size);
	my_src_size = ft_strlcpy(my_dest, src, dest_size);
	printf("GIVEN: src: %s  dest_size: %d\n", src, dest_size);
	printf("MINE: dest: %s  src_size: %d\n", my_dest, my_src_size);
	printf("ORIG: dest: %s  src_size: %d\n", sup_dest, sup_src_size);
	return (0);
}
