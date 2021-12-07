/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:17 by svieira           #+#    #+#             */
/*   Updated: 2021/12/07 15:15:25 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_sorted(t_int_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_index_min(t_int_list *stack)
{
	int	index;
	int	i_min;
	int	min;

	if (!stack)
		return (0);
	index = 1;
	i_min = 1;
	min = stack->nb;
	while (stack->next)
	{
		index++;
		if (stack->next->nb < min)
		{
			i_min = index;
			min = stack->next->nb;
		}
		stack = stack->next;
	}
	return (i_min);
}

int	get_index_max(t_int_list *stack)
{
	int	index;
	int	i_max;
	int	max;

	if (!stack)
		return (0);
	index = 1;
	i_max = 1;
	max = stack->nb;
	while (stack->next)
	{
		index++;
		if (stack->next->nb > max)
		{
			i_max = index;
			max = stack->next->nb;
		}
		stack = stack->next;
	}
	return (i_max);
}
