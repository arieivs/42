#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_list;

	new_list = ft_create_elem(data);
	new_list->next = *begin_list;
	*begin_list = new_list;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	int		i;

	if (size == 0)
		return (0);
	list = ft_create_elem((void *)strs[0]);
	i = 1;
	while (i < size)
	{
		ft_list_push_front(&list, (void *)strs[i]);
		i++;
	}
	return (list);
}

void	ft_print_del(void *data)
{
	printf("%s\n", (char *)data);
	while (*((char *)data))
	{
		*((char *)data) = 0;
		data++;
	}
}

int	main(int ac, char **av)
{
	t_list	*list;
	void	(*pt_print_del)(void*);

	list = ft_list_push_strs(ac, av);
	pt_print_del = &ft_print_del;
	ft_list_clear(list, pt_print_del);
	return (0);
}
