/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:14:17 by svieira           #+#    #+#             */
/*   Updated: 2021/12/09 11:46:30 by svieira          ###   ########.fr       */
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

void	get_min(t_intlst *stack, t_limits *limits)
{
	int	index;
	int	i_min;
	int	min;

	if (!stack)
		return ;
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
	limits->i_min = i_min;
	limits->min = min;
}

void	get_max(t_intlst *stack, t_limits *limits)
{
	int	index;
	int	i_max;
	int	max;

	if (!stack)
		return ;
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
	limits->i_max = i_max;
	limits->max = max;
}

void	get_mean_and_size(t_intlst *stack, t_limits *limits)
{
	int	mean;
	int	size;

	if (!stack)
		return ;
	mean = 0;
	size = 0;
	while (stack)
	{
		mean += stack->nb;
		size += 1;
		stack = stack->next;
	}
	mean /= size;
	limits->mean = mean;
	limits->size = size;
}

