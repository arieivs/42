/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:23:32 by svieira           #+#    #+#             */
/*   Updated: 2021/12/07 15:47:30 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>


int	main(int ac, char **av)
{
	t_intlst	*stack_a;
	t_intlst	*stack_b;
	t_intlst	*steps;
	int		*arr;

	//To do: think about errors
	if (ac == 1)
		return (0);
	if (invalid_input(ac, av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	// not sure if I'll keep the array...
	arr = create_arr(ac, av);
	if (duplicate_numbers(ac - 1, arr))
	{
		write(2, "Error\n", 6);
		free(arr);
		return (0);
	}
	// once input has been cleaned/checked:
	stack_a = create_stack(ac, av);
	stack_b = NULL;

	// once again, not sure:
	// quick_sort(arr, 0, ac - 1);

	if (is_sorted(stack_a))
		return (0);
	// for now:
	steps = NULL;
	if (ac == 4)
		sort_3(&stack_a, &steps);

	print_instructions(steps);
	// cleaning the house
	ft_intlst_clear(&stack_a, &ft_intlst_content_del);
	ft_intlst_clear(&stack_b, &ft_intlst_content_del);
	free(arr);
	return (0);
}
