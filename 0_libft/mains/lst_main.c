#include <stdio.h>
#include "../libft/libft.h"

int	main(void)
{
	int		x1 = 5;
	int		x2 = 10;
	int		x3 = 15;
	t_list	*list1;
	t_list	*list2;
	t_list	*listend;

	printf("\nLST NEW\n");
	list1 = ft_lstnew((void *)&x1);
	printf("new list content: %d\n", *(int *)list1->content);

	printf("\nLST ADD FRONT\n");
	list2 = ft_lstnew((void *)&x2);
	ft_lstadd_front(&list1, list2);
	printf("lst->content - expect: 10, got %d\n", *(int *)list1->content);
	printf("lst->next->content - expect: 5, got %d\n", *(int *)list1->next->content);

	printf("\nLST ADD BACK\n");
	listend = ft_lstnew((void *)&x3);
	ft_lstadd_back(&list1, listend);
	printf("lst->cntt - expect: 10, got %d\n", *(int *)list1->content);
	printf("lst->next->cntt - expect: 5, got %d\n", *(int *)list1->next->content);
	printf("lst->next->next->cntt - expect: 15, got %d\n", *(int *)list1->next->next->content);

	printf("\nLST SIZE\n");
	printf("expect: 3, got %d\n", ft_lstsize(list1));

	printf("\nLST LAST\n");
	printf("expect: 15, got %d\n", *(int *)(ft_lstlast(list1)->content));

	return (0);
}
