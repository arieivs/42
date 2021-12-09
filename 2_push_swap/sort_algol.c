/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:45 by svieira           #+#    #+#             */
/*   Updated: 2021/12/09 15:14:03 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

void	sort_3(t_intlst **stack, t_limits *limits, t_intlst **steps)
{
	if (is_sorted(*stack))
		return ;
	get_min(*stack, limits);
	get_max(*stack, limits);
	if (limits->i_max == 1 && limits->i_min == 2)
		op(ROTATE_A, stack, NULL, steps);
	else if (limits->i_max == 2 && limits->i_min == 3)
		op(REV_ROTATE_A, stack, NULL, steps);
	else
		op(SWAP_A, stack, NULL, steps);
	sort_3(stack, limits, steps);
}

void	sort_5(t_intlst **stack_a, t_intlst **stack_b, t_limits *limits,
		t_intlst **steps)
{
	int	times;

	times = 0;
	while (times < 2)
	{
		get_min(*stack_a, limits);
		while (limits->i_min != 1)
		{
			if (limits->i_min <= 3)
				op(ROTATE_A, stack_a, NULL, steps);
			else
				op(REV_ROTATE_A, stack_a, NULL, steps);
			get_min(*stack_a, limits);
		}
		op(PUSH_B, stack_a, stack_b, steps);
		times++;
	}
	sort_3(stack_a, limits, steps);
	op(PUSH_A, stack_b, stack_a, steps);
	op(PUSH_A, stack_b, stack_a, steps);
}

void	push_b_lower_half(t_intlst **stack_a, t_intlst **stack_b,
		t_limits *limits, t_intlst **steps)
{
	int	i;

	i = 0;
	get_mean_and_size(*stack_a, limits);
	while (i < limits->size)
	{
		if ((*stack_a)->nb < limits->mean)
			op(PUSH_B, stack_a, stack_b, steps);
		else
			op(ROTATE_A, stack_a, NULL, steps);
		i++;
	}
}

void	push_a_higher_half(t_intlst **stack_a, t_intlst **stack_b,
		t_limits *limits, t_intlst **steps)
{
	int	i;

	i = 0;
	get_mean_and_size(*stack_b, limits);
	while (i < limits->size)
	{
		if ((*stack_b)->nb > limits->mean)
			op(PUSH_A, stack_b, stack_a, steps);
		else
			op(ROTATE_B, stack_b, NULL, steps);
		i++;
	}
}

void	push_a_until_sorted(t_intlst **stack_a, t_intlst **stack_b,
		t_limits *limits, t_intlst **steps)
{
	while (*stack_b)
	{
		get_min(*stack_b, limits);
		get_mean_and_size(*stack_b, limits);
		while (limits->i_min != 1)
		{
			if (limits->i_min <= limits->size + 1)
				op(ROTATE_B, stack_b, NULL, steps);
			else
				op(REV_ROTATE_B, stack_b, NULL, steps);
			get_min(*stack_b, limits);
			get_mean_and_size(*stack_b, limits);
		}
		op(PUSH_A, stack_b, stack_a, steps);
		op(ROTATE_A, stack_a, NULL, steps);
	}
}

/*
 * ABOUT ABS_MIN_DEFINED
 * The first time I call push_b_lower_half,
 * when I call get_mean_and_size, I want it to consider the whole stack.
 * After that I want it to consider only the unsorted part of the stack,
 * thus I tell it to stop once it finds the minimum.
 * This obviously cannot happen the first time I call it, when nothing is sorted
 * which is why I set abs_min_defined to 0 in the beginning
 * and change it after I call push_b_lower_half for the first time
 */
void	sort_big(t_intlst **stack_a, t_intlst **stack_b, t_limits *limits,
		t_intlst **steps)
{
	// check if A is sorted and B empty => halting condition
	if (is_sorted(*stack_a))
		return ;
	if (!(*stack_b))
	{
		// push lower numbers from A to B
		push_b_lower_half(stack_a, stack_b, limits, steps);
		if (!limits->abs_min_defined)
		{
			limits->abs_min_defined = 1;
		}
		write(1, "A ", 2);
		print_stack(*stack_a);
		write(1, "B ", 2);
		print_stack(*stack_b);
	}
	else if (ft_intlst_size(*stack_b) > 10) // think about threshold
	{
		// push higher numbers from B to A
		push_a_higher_half(stack_a, stack_b, limits, steps);
		write(1, "A ", 2);
		print_stack(*stack_a);
		write(1, "B ", 2);
		print_stack(*stack_b);
	}
	else
	{
		// push to bottom of A in a sorted manner until B is emty
		push_a_until_sorted(stack_a, stack_b, limits, steps);
		write(1, "A ", 2);
		print_stack(*stack_a);
		write(1, "B ", 2);
		print_stack(*stack_b);
	}
	sort_big(stack_a, stack_b, limits, steps);
}

void	sort_stack(t_intlst **stack_a, t_intlst **steps)
{
	t_intlst	*stack_b;
	t_limits	limits;
	int			size_a;

	stack_b = NULL;
	size_a = ft_intlst_size(*stack_a);
	if (size_a <= 3)
		sort_3(stack_a, &limits, steps);
	else if (size_a <= 5)
		sort_5(stack_a, &stack_b, &limits, steps);
	else
	{
		get_min(*stack_a, &limits);
		limits.abs_min = limits.min;
		limits.abs_min_defined = 0;
		sort_big(stack_a, &stack_b, &limits, steps);
	}
	ft_intlst_clear(&stack_b, &ft_intlst_content_del);
}
