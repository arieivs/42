/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:07:21 by svieira           #+#    #+#             */
/*   Updated: 2021/05/14 15:00:16 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

void	swap(t_list **stack)
{
	t_list	*sec;

	// if pointer is NULL, is pointing at NULL or the list has 1 element
	if (!stack || !*stack || !((*stack)->next))
		return ;
	sec = (*stack)->next;
	(*stack)->next = sec->next;
	sec->next = *stack;
	*stack = sec;
}	

void	push(t_list **from, t_list **to)
{
	t_list	*move;
	if (!from || !*from)
	{
		printf("not enough\n");
		return ;
	}
	move = *from;
	*from = move->next;
	move->next = *to;
	*to = move;
}
