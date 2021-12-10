/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:45 by svieira           #+#    #+#             */
/*   Updated: 2021/12/10 01:43:15 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
		sort_big(stack_a, &stack_b, &limits, steps);
	}
	ft_intlst_clear(&stack_b, &ft_intlst_content_del);
	ft_intlst_clear(&limits, &ft_intlst_content_del);
}
