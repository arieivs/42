/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:50:14 by svieira           #+#    #+#             */
/*   Updated: 2021/06/08 11:32:44 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/* pseudo coding
 * a)
 * params: stack a, b, lenght, something else? maybe x? old mean_a?
 * if length < x, return (skip this step) -> how much should x be?
 * while i < length, or while stack_a->data < old mean_a if old mean_a exists
 * what if old_mean_a is zero??
 * maybe I can really trust on length?
 * should I do something before?
 * like... go through the array and measure the lenght? fuck my life
 * ?
 */

int	lst_mean(t_list *list)
{
	int	mean;

	mean = 0;
	while (list)
	{
		mean += *(int *)list->content;
		list = list->next;
	}
	return (mean);
}

int	split_stack_a(t_list **stack_a, t_list **stack_b, int length)
{
	int	moves;
	int	i;

	moves = 0;
	i = 0;
	if (length < 26) // think about this 26
		return (moves);
	while (i < length)
	{
		if (*(int *)(*stack_a)->content <= mean_a)
			moves = op("pb", stack_a, stack_b, moves); // rethink this way
		else
			moves = op("ra", stack_a, NULL, moves);
		i++;
	}
	return (moves);
}
