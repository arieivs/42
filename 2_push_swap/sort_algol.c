/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:45 by svieira           #+#    #+#             */
/*   Updated: 2021/12/09 18:19:16 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

void	sort_3(t_intlst **stack, t_intlst **steps)
{
	int	i_min;
	int	i_max;

	if (is_sorted(*stack))
		return ;
	i_min = get_index_min(*stack);
	i_max = get_index_max(*stack);
	if (i_max == 1 && i_min == 2)
		op(ROTATE_A, stack, NULL, steps);
	else if (i_max == 2 && i_min == 3)
		op(REV_ROTATE_A, stack, NULL, steps);
	else
		op(SWAP_A, stack, NULL, steps);
	sort_3(stack, steps);
}

void	sort_5(t_intlst **stack_a, t_intlst **stack_b, t_intlst **steps)
{
	int	times;
	int	i_min;

	times = 0;
	while (times < 2)
	{
		i_min = get_index_min(*stack_a);
		while (i_min != 1)
		{
			if (i_min <= 3)
				op(ROTATE_A, stack_a, NULL, steps);
			else
				op(REV_ROTATE_A, stack_a, NULL, steps);
			i_min = get_index_min(*stack_a);
		}
		op(PUSH_B, stack_a, stack_b, steps);
		times++;
	}
	sort_3(stack_a, steps);
	op(PUSH_A, stack_b, stack_a, steps);
	op(PUSH_A, stack_b, stack_a, steps);
}

void	push_lower_to_b(t_intlst **stack_a, t_intlst **stack_b,
		t_intlst **limits, t_intlst **steps)
{
	static int	partly_sorted = 0;
	int	i;
	int	size;
	int	mean;

	//get_mean_and_size(*stack_a, limits, limits->a_part_sorted);
	// get the new breakpoint
	if (!partly_sorted)
		partly_sorted = 1;
	i = 0;
	size = ft_intlst_size(*stack_a);
	mean = get_mean(*stack_a, *limits, partly_sorted);
	while (i < size)
	{
		if ((*stack_a)->nb < mean)
			op(PUSH_B, stack_a, stack_b, steps);
		else
			op(ROTATE_A, stack_a, NULL, steps);
		i++;
	}
}

void	push_higher_to_a(t_intlst **stack_a, t_intlst **stack_b,
		t_intlst **limits, t_intlst **steps)
{
	int	i;
	int	size;
	int	mean;

	i = 0;
	size = ft_intlst_size(*stack_b);
	mean = get_mean(*stack_b, *limits, 0);
	//get_mean_and_size(*stack_b, limits, 0);
	while (i < size)
	{
		if ((*stack_b)->nb > mean)
			op(PUSH_A, stack_b, stack_a, steps);
		else
			op(ROTATE_B, stack_b, NULL, steps);
		i++;
	}
}

void	push_sorted_to_a(t_intlst **stack_a, t_intlst **stack_b,
		t_intlst **limits, t_intlst **steps)
{
	int	i_min;
	int	mean;
	int	size;

	while (*stack_b)
	{
		i_min = get_index_min(*stack_b);
		//get_mean_and_size(*stack_b, limits, 0);
		mean = get_mean(*stack_b, *limits, 0);
		size = ft_intlst_size(*stack_b);
		while (i_min != 1)
		{
			if (i_min <= size + 1)
				op(ROTATE_B, stack_b, NULL, steps);
			else
				op(REV_ROTATE_B, stack_b, NULL, steps);
			i_min = get_index_min(*stack_b);
			//get_mean_and_size(*stack_b, limits, 0);
			mean = get_mean(*stack_b, *limits, 0);
			size = ft_intlst_size(*stack_b);
		}
		op(PUSH_A, stack_b, stack_a, steps);
		op(ROTATE_A, stack_a, NULL, steps);
	}
}

/*
 * ABOUT A_PART_SORTED
 * The first time I call push_b_lower_half,
 * when I call get_mean_and_size, I want it to consider the whole stack.
 * After that I want it to consider only the unsorted part of the stack,
 * thus I tell it to stop once it finds the minimum.
 * This obviously cannot happen the first time I call it, when nothing is sorted
 * which is why I set a_part_sorted to 0 in the beginning
 * and change it after I call push_b_lower_half for the first time
 */
void	sort_big(t_intlst **stack_a, t_intlst **stack_b, t_intlst **limits,
		t_intlst **steps)
{
	// check if A is sorted and B empty => halting condition
	if (is_sorted(*stack_a))
		return ;
	if (!(*stack_b))
	{
		// push lower numbers from A to B
		push_lower_to_b(stack_a, stack_b, limits, steps);
		write(1, "A ", 2);
		print_stack(*stack_a);
		write(1, "B ", 2);
		print_stack(*stack_b);
	}
	else if (ft_intlst_size(*stack_b) > 10) // think about threshold
	{
		// push higher numbers from B to A
		push_higher_to_a(stack_a, stack_b, limits, steps);
		write(1, "A ", 2);
		print_stack(*stack_a);
		write(1, "B ", 2);
		print_stack(*stack_b);
	}
	else
	{
		// push to bottom of A in a sorted manner until B is emty
		push_sorted_to_a(stack_a, stack_b, limits, steps);
		write(1, "A ", 2);
		print_stack(*stack_a);
		write(1, "B ", 2);
		print_stack(*stack_b);
	}
	//if (!limits->a_part_sorted)
	//	limits->a_part_sorted = 1;
	sort_big(stack_a, stack_b, limits, steps);
}

void	sort_stack(t_intlst **stack_a, t_intlst **steps)
{
	t_intlst	*stack_b;
	t_intlst	*limits;
	int			size_a;

	stack_b = NULL;
	limits = NULL;
	size_a = ft_intlst_size(*stack_a);
	if (size_a <= 3)
		sort_3(stack_a, steps);
	else if (size_a <= 5)
		sort_5(stack_a, &stack_b, steps);
	else
	{
		limits = get_min_and_max(*stack_a);
		//get_min(*stack_a, &limits);
		//limits.abs_min = limits.min;
		//limits.a_part_sorted = 0;
		sort_big(stack_a, &stack_b, &limits, steps);
	}
	ft_intlst_clear(&stack_b, &ft_intlst_content_del);
}
