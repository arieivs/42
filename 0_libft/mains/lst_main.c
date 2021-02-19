#include <stdio.h>
#include "../libft/libft.h"

int	main(void)
{
	int		x1 = 5;
	int		x2 = 10;
	t_list	*list1;
	t_list	*list2;

	printf("\nLST NEW\n");
	list1 = ft_lstnew((void *)&x1);
	printf("new list content: %d\n", *(int *)list1->content);

	printf("\nLST ADD FRONT\n");
	list2 = ft_lstnew((void *)&x2);
	ft_lstadd_front(&list1, list2);
	printf("lst->content - expect: 10, got %d\n", *(int *)list1->content);
	printf("lst->next->content - expect: 5, got %d\n", *(int *)list1->next->content);

	printf("\nLST SIZE\n");
	printf("expect: 2, got %d\n", ft_lstsize(list1));

	return (0);
}
