#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

int	ft_list_size(t_list *begin_list);

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = 0;
	return (list);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_list;

	new_list = ft_create_elem(data);
	new_list->next = *begin_list;
	*begin_list = new_list;
}

int	main(void)
{
	int data1;
	int data2;
	int data3;
	t_list *list;
	int size;
	
	data1 = 10;
	data2 = 20;
	data3 = 30;
	list = ft_create_elem((void *)&data1);
	ft_list_push_front(&list, (void *)&data2);
	ft_list_push_front(&list, (void *)&data3);
	size = ft_list_size(list);
	printf("list size: %d\n", size);
	printf("list first item data: %d\n", *((int *)list->data));
	return (0);
}
