/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_algol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:45 by svieira           #+#    #+#             */
/*   Updated: 2021/12/10 01:43:53 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
 * Room for improvement:
 * if (ft_intlst_size(*limits) < 2) => error message and exit gracefully
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

/*
 * Pushes the chunck with the highest numbers back to the top of stack A
 * Adds a new breakpoint to the limits list, the current mean of stack B,
 * which will be used the next time push_lower_to_b is called.
 */
void	push_higher_to_a(t_intlst **stack_a, t_intlst **stack_b,
		t_intlst **limits, t_intlst **steps)
{
	int	i;
	int	size;
	int	mean;

	i = 0;
	size = ft_intlst_size(*stack_b);
	mean = get_mean(*stack_b);
	ft_intlst_push_right_order(limits, mean);
	while (i < size)
	{
		if ((*stack_b)->nb > mean)
			op(PUSH_A, stack_b, stack_a, steps);
		else
			op(ROTATE_B, stack_b, NULL, steps);
		i++;
	}
}

/*
 * Pushes all numbers in stack B to the bottom of stack A in order
 */
void	push_sorted_to_a(t_intlst **stack_a, t_intlst **stack_b,
		t_intlst **steps)
{
	int	i_min;
	int	size;

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
	if (is_sorted(*stack_a) && !(*stack_b))
		return ;
	if (!(*stack_b))
		push_lower_to_b(stack_a, stack_b, limits, steps);
	else if (ft_intlst_size(*stack_b) > THRESHOLD) 
		push_higher_to_a(stack_a, stack_b, limits, steps);
	else
		push_sorted_to_a(stack_a, stack_b, steps);
	sort_big(stack_a, stack_b, limits, steps);
}
