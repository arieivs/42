/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:29:36 by svieira           #+#    #+#             */
/*   Updated: 2021/12/06 23:04:53 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// swap the first two elements of a stack
void	swap(t_int_list **stack)
{
	t_int_list	*sec;

	// if pointer is NULL, is pointing at NULL or the list has 1 element
	if (!stack || !*stack || !((*stack)->next))
		return ;
	sec = (*stack)->next;
	(*stack)->next = sec->next;
	sec->next = *stack;
	*stack = sec;
}	

// push the first element of a stack to another one
void	push(t_int_list **from, t_int_list **to)
{
	t_int_list	*move;

	if (!from || !*from)
		return ;
	move = *from;
	*from = move->next;
	move->next = *to;
	*to = move;
}

// place the first element of a stack as its last
void	rotate(t_int_list **stack)
{
	t_int_list	*last;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	last = (*stack)->next;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = 0;
}

// place the last element of a stack as its first
void	reverse_rotate(t_int_list **stack)
{
	t_int_list	*bef_last;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	bef_last = *stack;
	while (bef_last->next->next)
		bef_last = bef_last->next;
	bef_last->next->next = *stack;
	*stack = bef_last->next;
	bef_last->next = 0;
}

// not sure this router makes sense... I feel I'm doubling the if statements
int	op(char *op, t_int_list **stack, t_int_list **sec_stack, int instructions)
{
	if (op[0] == 'r' && op[1] == 'r')
	{
		reverse_rotate(stack);
		write(1, op, 3);
	}
	else
	{
		if (op[0] == 'r')
			rotate(stack);
		else if (op[0] == 's')
			swap(stack);
		else if (op[0] == 'p')
			push(stack, sec_stack);
		write(1, op, 2);
	}
	write(1, "\n", 1);
	return (instructions++);
}
