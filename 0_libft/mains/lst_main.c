#include <stdio.h>
#include "../libft/libft.h"

int	main(void)
{
	int		data = 10;
	t_list	*list;

	printf("\nLSTNEW\n");
	list = ft_lstnew((void *)&data);
	printf("new list content: %d\n", *(int *)list->content);
	return (0);
}
