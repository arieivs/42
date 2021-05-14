#include "includes/push_swap.h"
#include <stdio.h>

void	swap(t_list **stack);

int	main(void)
{
	int		x1 = 5;
	int		x2 = 7;
	int		x3 = 1;
	int		x4 = 3;
	t_list	*ele1;
	t_list	*ele2;
	t_list	*ele3;
	t_list	*ele4;
	t_list	*null;

	// making sure nothing happens when list has only 1 or no elements
	swap(NULL);
	null = NULL;
	swap(&null);
	ele1 = ft_lstnew((void *)&x1);
	swap(&ele1);

	// creating the list
	ele2 = ft_lstnew((void *)&x2);
	ft_lstadd_back(&ele1, ele2);
	ele3 = ft_lstnew((void *)&x3);
	ft_lstadd_back(&ele1, ele3);
	ele4 = ft_lstnew((void *)&x4);
	ft_lstadd_back(&ele1, ele4);
	printf("%d %d ", *(int *)ele1->content, *(int *)ele1->next->content);
	printf("%d ", *(int *)ele1->next->next->content);
	printf("%d\n", *(int *)ele1->next->next->next->content);

	// swaping
	swap(&ele1);
	printf("%d %d ", *(int *)ele1->content, *(int *)ele1->next->content);
	printf("%d ", *(int *)ele1->next->next->content);
	printf("%d\n", *(int *)ele1->next->next->next->content);

	return (0);
}
