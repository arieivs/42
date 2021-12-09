/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:45 by svieira           #+#    #+#             */
/*   Updated: 2021/12/09 23:18:42 by svieira          ###   ########.fr       */
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
	i_min = get_min(*stack, RETURN_INDEX);
	i_max = get_max(*stack, RETURN_INDEX);
	if (i_max == 1 && i_min == 2)
		op(ROTATE_A, stack, NULL, steps);
	else if (i_max == 2 && i_min == 3)
		op(REV_ROTATE_A, stack, NULL, steps);
	else
		op(SWAP_A, stack, NULL, steps);
	sort_3(stack, steps);
}

/*
 * Pushes two smallest numbers to stack B
 * Orders stack A with sort_3
 * Pushes two smallest numbers back to stack A
 */
void	sort_5(t_intlst **stack_a, t_intlst **stack_b, t_intlst **steps)
{
	int	times;
	int	i_min;

	times = 0;
	while (times < 2)
	{
		i_min = get_min(*stack_a, RETURN_INDEX);
		while (i_min != 1)
		{
			if (i_min <= 3)
				op(ROTATE_A, stack_a, NULL, steps);
			else
				op(REV_ROTATE_A, stack_a, NULL, steps);
			i_min = get_min(*stack_a, RETURN_INDEX);
		}
		op(PUSH_B, stack_a, stack_b, steps);
		times++;
	}
	sort_3(stack_a, steps);
	op(PUSH_A, stack_b, stack_a, steps);
	op(PUSH_A, stack_b, stack_a, steps);
}

/*
 * Pushes the chunk with the lowest numbers to stack B.
 * The first time this function is called, right at the beginning,
 * the highest numbers go to the bottom of stack A.
 * After that, stack A will be pre-sorted on top and sorted at the bottom,
 * so we don't want to put unordered numbers at the bottom of A anymore.
 * Plus we don't have to, as each chunk is "defined" by a breakpoint.
 * The variable partly_sorted allows the function to have a different behaviour
 * the first time the function is called.
 * The breakpoints are stored in the limits list.
 * The first time this function is called, limits has min, mean, max.
 * The next function adds new breakpoints to the list.
 * Each time a chunk is moved, the lowest limit is removed, so that we can move
 * to the next chunk the next time the function is called.
 */
void	push_lower_to_b(t_intlst **stack_a, t_intlst **stack_b,
		t_intlst **limits, t_intlst **steps)
{
	static int	partly_sorted = 0;
	int			i;
	int			size;

	i = 0;
	size = ft_intlst_size(*stack_a);
	while (i < size)
	{
		if ((*stack_a)->nb >= (*limits)->nb &&
			(*stack_a)->nb <= (*limits)->next->nb)
			op(PUSH_B, stack_a, stack_b, steps);
		else if (!partly_sorted)
			op(ROTATE_A, stack_a, NULL, steps);
		else
			break ;
		i++;
	}
	ft_intlst_delfirst(limits, &ft_intlst_content_del);
	if (!partly_sorted)
		partly_sorted = 1;
}

void	push_higher_to_a(t_intlst **stack_a, t_intlst **stack_b,
		t_intlst **limits, t_intlst **steps)
{
	int	i;
	int	size;
	int	mean;
	(void)limits;

	i = 0;
	size = ft_intlst_size(*stack_b);
	// find a way to add new breakpoints
	mean = get_mean(*stack_b); // needs to be changed
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
	int	size;
	(void)limits;

	while (*stack_b)
	{
		i_min = get_min(*stack_b, RETURN_INDEX);
		size = ft_intlst_size(*stack_b);
		while (i_min != 1)
		{
			if (i_min <= (size / 2 + 1))
				op(ROTATE_B, stack_b, NULL, steps);
			else
				op(REV_ROTATE_B, stack_b, NULL, steps);
			i_min = get_min(*stack_b, RETURN_INDEX);
			size = ft_intlst_size(*stack_b);
		}
		op(PUSH_A, stack_b, stack_a, steps);
		op(ROTATE_A, stack_a, NULL, steps);
	}
}

void	sort_big(t_intlst **stack_a, t_intlst **stack_b, t_intlst **limits,
		t_intlst **steps)
{
	// check if A is sorted and B empty => halting condition
	if (is_sorted(*stack_a) && !(*stack_b))
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
		limits = get_min_mean_max(*stack_a);
		//printf("min %d, mean %d, max %d\n", limits->nb, limits->next->nb, limits->next->next->nb);
		sort_big(stack_a, &stack_b, &limits, steps);
	}
	ft_intlst_clear(&stack_b, &ft_intlst_content_del);
}
