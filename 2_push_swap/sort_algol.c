/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:45 by svieira           #+#    #+#             */
/*   Updated: 2021/12/07 16:30:22 by svieira          ###   ########.fr       */
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
