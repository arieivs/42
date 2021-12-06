/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:23:32 by svieira           #+#    #+#             */
/*   Updated: 2021/12/06 16:06:54 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_del(void *content)
{
	*(int *)content = 0;
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;
	void	(*pt_del)(void*);

	//To do: think about errors
	// once input has been cleaned/checked:
	stack_a = create_stack(ac, av);
	stack_b = NULL;
	arr = create_arr(ac, av);
	//quick_sort(arr, 0, ac - 1);



	// cleaning the house
	pt_del = &ft_del;
	ft_lstclear(&stack_a, pt_del);
	ft_lstclear(&stack_b, pt_del);
	free(arr);
	return (0);
}
