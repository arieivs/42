/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:45 by svieira           #+#    #+#             */
/*   Updated: 2021/12/08 17:01:47 by svieira          ###   ########.fr       */
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

void	sort_big(t_intlst **stack_a, t_intlst **stack_b, t_limits *limits,
		t_intlst **steps)
{
	(void)stack_b;
	(void)steps;

	get_mean(*stack_a, limits);
	get_min(*stack_a, limits);
	/*while (limits->min < limits->mean)
	{
		while (limits->i_min != 1)
		{
			if (limits->i_min <= limits->size / 2)
				op(ROTATE_A, stack_a, NULL, steps);
			else
				op(REV_ROTATE_A, stack_a, NULL, steps);
				get_min(*stack_a, limits);
		}
		op(PUSH_B, stack_a, stack_b, steps);
	}*/
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
		sort_big(stack_a, &stack_b, &limits, steps);
	ft_intlst_clear(&stack_b, &ft_intlst_content_del);
}
