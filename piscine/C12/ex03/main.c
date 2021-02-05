#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list);

t_list	*ft_create_elem(void *data)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->data = data;
	new_list->next = 0;
	return (new_list);
}

void	ft_list_push_front(t_list **begin, void *data)
{
	t_list *new_list;

	new_list = ft_create_elem(data);
	new_list->next = *begin;
	*begin = new_list;
}

int	main(void)
{
	int data1;
	int data2;
	int data3;
	t_list *list;
	t_list *last;

	data1 = 1;
	data2 = 2;
	data3 = 3;
	list = ft_create_elem((void *)&data1);
	ft_list_push_front(&list, (void *)&data2);
	ft_list_push_front(&list, (void *)&data3);
	last = ft_list_last(list);
	printf("first item data: %d\n", *((int *)list->data));
	printf("last item data: %d\n", *((int *)last->data));
	return (0);
}
