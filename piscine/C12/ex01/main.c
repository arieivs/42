#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data);

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = data
	list->next = 0;
	return (list);
}

int main(void)
{
	int data1;
	int data2;
	t_list list;

	data1 = 10;
	data2 = 20;
	list = ft_create_elem((void *)&data1);
	ft_list_push_front(&list, (void *)&data2);
	printf("front list %p with data %d\n", 

