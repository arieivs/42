/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:45 by svieira           #+#    #+#             */
/*   Updated: 2021/12/07 23:36:09 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

void	sort_stack(int size_a, t_intlst **stack_a, t_intlst **steps)
{
	t_intlst	*stack_b;

	stack_b = NULL;
	if (size_a <= 3)
		sort_3(stack_a, steps);
	else if (size_a <= 5)
		sort_5(stack_a, &stack_b, steps);
	// else
	// sort_big
	ft_intlst_clear(&stack_b, &ft_intlst_content_del);
}
