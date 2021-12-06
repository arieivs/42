#include "includes/push_swap.h"
#include <stdio.h>

static void	ft_print_del(void *content)
{
	printf("deleting %d\n", *(int *)content);
	*(int *)content = 0;
}

t_list	*create_stack_test(void)
{
	int		x1 = 5;
	int		x2 = 7;
	int		x3 = 1;
	int		x4 = 3;
	t_list	*ele2;
	t_list	*ele3;
	t_list	*ele4;
	t_list	*ele1;

	ele1 = ft_lstnew((void *)&x1);
	printf("created %d ", *(int *)ele1->content);
	ele2 = ft_lstnew((void *)&x2);
	ft_lstadd_back(&ele1, ele2);
	printf("created %d ", *(int *)ele1->next->content);
	ele3 = ft_lstnew((void *)&x3);
	ft_lstadd_back(&ele1, ele3);
	printf("created %d ", *(int *)ele1->next->next->content);
	ele4 = ft_lstnew((void *)&x4);
	ft_lstadd_back(&ele1, ele4);
	printf("created %d ", *(int *)ele1->next->next->next->content);
	return (ele1);
}

int	main(void)
{
	t_list	*ele1 = NULL;
	t_list	*null;
	void	(*pt_print_del)(void*);

	null = NULL;
	printf("\nORIGINAL LIST\n");
	ele1 = create_stack_test();
	printf("%d %d ", *(int *)ele1->content, *(int *)ele1->next->content);
	printf("%d ", *(int *)ele1->next->next->content);
	printf("%d\n", *(int *)ele1->next->next->next->content);

	printf("\nCLEANING\n");
	pt_print_del = &ft_print_del;
	ft_lstclear(&ele1, pt_print_del);
	ft_lstclear(&null, pt_print_del);
	return (0);
}

