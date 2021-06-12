#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs);

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = 0;
	return (list);
}

int	main(int ac, char **av)
{
	t_list	*list;

	list = ft_list_push_strs(ac, av);
	while (list)
	{
		printf("%s\n", (char *)list->data);
		list = list->next;
	}
	return (0);
}
