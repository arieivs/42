#include <stdio.h>
#include "../libft/libft.h"

static void	ft_print_del(void *content)
{
	printf("deleting %d\n", *(int *)content);
	*(int *)content = 0;
}

static void	ft_print_double(void *content)
{
	printf("%d x 2 = %d\n", *(int *)content, *(int *)content * 2);
}

static void	*ft_double(void *content)
{
	void	*doub;

	doub = malloc(sizeof(int));
	*(int *)doub = *(int *)content * 2;
	return (doub);
}

int	main(void)
{
	int		x1 = 5;
	int		x2 = 10;
	int		x3 = 15;
	int		x4 = 20;
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*list4;
	t_list	*listmapped;
	void	(*pt_print_del)(void*);
	void	(*pt_print_double)(void *);
	void	*(*pt_double)(void *);

	printf("\nLST NEW\n");
	list1 = ft_lstnew((void *)&x1);
	printf("new list content: %d\n", *(int *)list1->content);

	printf("\nLST ADD FRONT\n");
	list2 = ft_lstnew((void *)&x2);
	ft_lstadd_front(&list1, list2);
	printf("lst->content - expect: 10, got %d\n", *(int *)list1->content);
	printf("lst->next->content - expect: 5, got %d\n", *(int *)list1->next->content);

	printf("\nLST ADD BACK\n");
	list3 = ft_lstnew((void *)&x3);
	ft_lstadd_back(&list1, list3);
	list4 = ft_lstnew((void *)&x4);
	ft_lstadd_back(&list1, list4);
	printf("lst->cntt - expect: 10, got %d\n", *(int *)list1->content);
	printf("lst->next->cntt - expect: 5, got %d\n", *(int *)list1->next->content);
	printf("lst->next->next->cntt - expect: 15, got %d\n", *(int *)list1->next->next->content);
	printf("lst->next->next->next->cntt - expect: 20, got %d\n", *(int *)list1->next->next->next->content);

	printf("\nLST SIZE\n");
	printf("expect: 4, got %d\n", ft_lstsize(list1));

	printf("\nLST LAST\n");
	printf("expect: 20, got %d\n", *(int *)(ft_lstlast(list1)->content));

	pt_print_del = &ft_print_del;
	printf("\nLST DEL ONE\n");
	ft_lstdelone(list1->next, pt_print_del);
	list1->next = list3;

	pt_print_double = &ft_print_double;
	printf("\nLST ITER\n");
	ft_lstiter(list1, pt_print_double);

	pt_double = &ft_double;
	printf("\nLST MAP\n");
	listmapped = ft_lstmap(list1, pt_double, pt_print_del);
	printf("lst->cntt - expect: 20, got %d\n", *(int *)listmapped->content);
	printf("lst->next->cntt - expect: 30, got %d\n", *(int *)listmapped->next->content);
	printf("lst->next->next->cntt - expect: 40, got %d\n", *(int *)listmapped->next->next->content);

	printf("\nLST CLEAR\n");
	ft_lstclear(&list1, pt_print_del);

	printf("\nEND\n");
	return (0);
}
