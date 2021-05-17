/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:29:36 by svieira           #+#    #+#             */
/*   Updated: 2021/05/17 13:15:32 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

// swap the first two elements of a stack
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

// push the first element of a stack to another one
void	push(t_list **from, t_list **to)
{
	t_list	*move;

	if (!from || !*from)
		return ;
	move = *from;
	*from = move->next;
	move->next = *to;
	*to = move;
}

// place the first element of a stack as its last
void	rotate(t_list **stack)
{
	t_list	*last;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = 0;
}
