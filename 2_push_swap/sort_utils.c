/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:17 by svieira           #+#    #+#             */
/*   Updated: 2021/12/09 23:16:14 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

int	is_sorted(t_intlst *stack)
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

int	get_min(t_intlst *stack, int return_what)
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
	if (return_what == RETURN_INDEX)
		return (i_min);
	return (min);
}

int	get_max(t_intlst *stack, int return_what)
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
	if (return_what == RETURN_INDEX)
		return(i_max);
	return (max);
}

int	get_mean(t_intlst *stack)
{
	int	mean;
	int	size;

	if (!stack)
		return (0);
	mean = 0;
	size = 0;
	while (stack)
	{
		mean += stack->nb;
		size += 1;
		stack = stack->next;
	}
	mean /= size;
	return (mean);
}

t_intlst	*get_min_mean_max(t_intlst *stack)
{
	t_intlst	*limits;

	limits = ft_intlst_new(get_min(stack, RETURN_VALUE));
	ft_intlst_push_back(&limits, get_mean(stack));
	ft_intlst_push_back(&limits, get_max(stack, RETURN_VALUE));
	return (limits);
}

