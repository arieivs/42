#include "includes/push_swap.h"
#include <stdio.h>

static void	ft_print_del(int nb)
{
	printf("deleting %d\n", nb);
	nb = 0;
}

int	main(void)
{
	int		x1 = 5;
	int		x2 = 7;
	int		x3 = 1;
	int		x4 = 3;
	t_intlst	*ele1;
	t_intlst	*ele2;
	t_intlst	*ele3;
	t_intlst	*ele4;
	t_intlst	*null;

	null = NULL;
	printf("\nORIGINAL LIST\n");
	ele1 = ft_intlst_new(x1);
	ele2 = ft_intlst_new(x2);
	ft_intlst_add_back(&ele1, ele2);
	ele3 = ft_intlst_new(x3);
	ft_intlst_add_back(&ele1, ele3);
	ele4 = ft_intlst_new(x4);
	ft_intlst_add_back(&ele1, ele4);
	printf("%d %d ", ele1->nb, ele1->next->nb);
	printf("%d ", ele1->next->next->nb);
	printf("%d\n", ele1->next->next->next->nb);

	printf("\nSWAP\n");
	// making sure nothing happens when list has only 1 or no elements
	swap(NULL);
	swap(&null);
	swap(&ele4);

	// swaping and showing the result
	swap(&ele1);
	printf("%d %d ", ele1->nb, ele1->next->nb);
	printf("%d ", ele1->next->next->nb);
	printf("%d\n", ele1->next->next->next->nb);

	printf("\nROTATE/SHIFT\n");
	rotate(NULL);
	rotate(&null);
	rotate(&ele4);
	rotate(&ele1);
	printf("%d %d ", ele1->nb, ele1->next->nb);
	printf("%d ", ele1->next->next->nb);
	printf("%d\n", ele1->next->next->next->nb);

	printf("\nREVERSE ROTATE/UNSHIFT\n");
	reverse_rotate(NULL);
	reverse_rotate(&null);
	reverse_rotate(&ele2);
	reverse_rotate(&ele1);
	printf("%d %d ", ele1->nb, ele1->next->nb);
	printf("%d ", ele1->next->next->nb);
	printf("%d\n", ele1->next->next->next->nb);

	printf("\nPUSH\n");
	// making sure nothing happens when list from is empty
	push(NULL, &ele1);
	push(&null, &ele1);

	// pushing
	push(&ele1, &null);
	printf("from %d %d ", ele1->nb, ele1->next->nb);
	printf("%d\n", ele1->next->next->nb);
	printf("tooo %d\n", null->nb);
	push(&ele1, &null);
	printf("from %d %d\n", ele1->nb, ele1->next->nb);
	printf("tooo %d %d\n", null->nb, null->next->nb);

	printf("\nCLEANING\n");
	ft_intlst_clear(&ele1, &ft_print_del);
	ft_intlst_clear(&null, &ft_print_del);
	return (0);
}

