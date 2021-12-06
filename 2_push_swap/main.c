/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:23:32 by svieira           #+#    #+#             */
/*   Updated: 2021/12/06 19:20:23 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

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
	if (ac == 1)
		return (0);
	if (non_digits_input(ac, av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	// not sure if I'll keep the array...
	arr = create_arr(ac, av);
	if (invalid_numbers(ac - 1, arr))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	// once input has been cleaned/checked:
	stack_a = create_stack(ac, av);
	stack_b = NULL;

	//once again, not sure:
	//quick_sort(arr, 0, ac - 1);

	// if is_sorted(stack_a) && is_empty(stack_b)
	// return (0);
	// sort

	// cleaning the house
	pt_del = &ft_del;
	ft_lstclear(&stack_a, pt_del);
	ft_lstclear(&stack_b, pt_del);
	free(arr);
	return (0);
}
