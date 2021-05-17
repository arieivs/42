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

	null = NULL;
	printf("\nORIGINAL LIST\n");
	ele1 = ft_lstnew((void *)&x1);
	ele2 = ft_lstnew((void *)&x2);
	ft_lstadd_back(&ele1, ele2);
	ele3 = ft_lstnew((void *)&x3);
	ft_lstadd_back(&ele1, ele3);
	ele4 = ft_lstnew((void *)&x4);
	ft_lstadd_back(&ele1, ele4);
	printf("%d %d ", *(int *)ele1->content, *(int *)ele1->next->content);
	printf("%d ", *(int *)ele1->next->next->content);
	printf("%d\n", *(int *)ele1->next->next->next->content);

	printf("\nSWAP\n");
	// making sure nothing happens when list has only 1 or no elements
	swap(NULL);
	swap(&null);
	swap(&ele4);

	// swaping and showing the result
	swap(&ele1);
	printf("%d %d ", *(int *)ele1->content, *(int *)ele1->next->content);
	printf("%d ", *(int *)ele1->next->next->content);
	printf("%d\n", *(int *)ele1->next->next->next->content);

	printf("\nROTATE/SHIFT\n");
	rotate(NULL);
	rotate(&null);
	rotate(&ele4);
	rotate(&ele1);
	printf("%d %d ", *(int *)ele1->content, *(int *)ele1->next->content);
	printf("%d ", *(int *)ele1->next->next->content);
	printf("%d\n", *(int *)ele1->next->next->next->content);

	printf("\nREVERSE ROTATE/UNSHIFT\n");
	reverse_rotate(NULL);
	reverse_rotate(&null);
	reverse_rotate(&ele2);
	reverse_rotate(&ele1);
	printf("%d %d ", *(int *)ele1->content, *(int *)ele1->next->content);
	printf("%d ", *(int *)ele1->next->next->content);
	printf("%d\n", *(int *)ele1->next->next->next->content);

	printf("\nPUSH\n");
	// making sure nothing happens when list from is empty
	push(NULL, &ele1);
	push(&null, &ele1);

	// pushing
	push(&ele1, &null);
	printf("from %d %d ", *(int *)ele1->content, *(int *)ele1->next->content);
	printf("%d\n", *(int *)ele1->next->next->content);
	printf("tooo %d\n", *(int *)null->content);
	push(&ele1, &null);
	printf("from %d %d\n", *(int *)ele1->content, *(int *)ele1->next->content);
	printf("tooo %d %d\n", *(int *)null->content, *(int *)null->next->content);

	// cleaning the house
	// need to delete lists in the end
	return (0);
}

