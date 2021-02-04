#include "ft_list.h"
#include <stdio.h>

t_list	*ft_create_elem(void *data);

int	main(void)
{
	int data;
	t_list *list;

	data = 10;
	list = ft_create_elem((void *)&data);
	printf("list data: %d\n", *((int *)list->data));
	return (0);
}
