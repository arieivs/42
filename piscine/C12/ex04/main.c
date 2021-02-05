#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data);

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->data = data;
	list->next = 0;
	return (list);
}

int main(void)
{
	int x;
	int y;
	int z;
	t_list *list;

	x = 1;
	y = 2;
	z = 3;
	list = ft_create_elem((void *)&x);
	ft_list_push_back(&list, (void *)&y);
	ft_list_push_back(&list, (void *)&z);
	printf("1st item: %d\n", *((int *)list->data));
	printf("2nd item: %d\n", *((int *)list->next->data));
	printf("3rd item: %d\n", *((int *)list->next->next->data));
	return (0);
}
