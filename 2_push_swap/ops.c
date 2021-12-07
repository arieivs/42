/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:29:36 by svieira           #+#    #+#             */
/*   Updated: 2021/12/07 15:46:14 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*
** swap the first two elements of a stack
** if pointer is NULL, is pointing at NULL or the list has 1 element
** do nothing
*/
void	swap(t_intlst **stack)
{
	t_intlst	*sec;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	sec = (*stack)->next;
	(*stack)->next = sec->next;
	sec->next = *stack;
	*stack = sec;
}	

/*
** push the first element of a stack to another one
*/
void	push(t_intlst **from, t_intlst **to)
{
	t_intlst	*move;

	if (!from || !*from)
		return ;
	move = *from;
	*from = move->next;
	move->next = *to;
	*to = move;
}

/*
** place the first element of a stack as its last
*/
void	rotate(t_intlst **stack)
{
	t_intlst	*last;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	last = (*stack)->next;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = 0;
}

/*
** place the last element of a stack as its first
*/
void	reverse_rotate(t_intlst **stack)
{
	t_intlst	*bef_last;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	bef_last = *stack;
	while (bef_last->next->next)
		bef_last = bef_last->next;
	bef_last->next->next = *stack;
	*stack = bef_last->next;
	bef_last->next = 0;
}

/*
** operations router
** calls the right operation and adds the instruction to the steps list
*/
void	op(t_ops op, t_intlst **stack, t_intlst **sec_stack, t_intlst **steps)
{
	// get last element from steps
	
	if (op == SWAP_A || op == SWAP_B)
	{
		swap(stack);
		// if last element is SWAP other stack, exchange last for SWAP_A_B
		// else	
		ft_intlst_push_back(steps, (int)op);
	}
	else if (op == PUSH_A || op == PUSH_B)
	{
		push(stack, sec_stack);
		ft_intlst_push_back(steps, (int)op);
	}
	if (op == ROTATE_A || op == ROTATE_B)
	{
		rotate(stack);
		// if last element is ROTATE other stack, exchange last for ROTATE_A_B
		// else	
		ft_intlst_push_back(steps, (int)op);
	}
	if (op == REV_ROTATE_A || op == REV_ROTATE_B)
	{
		reverse_rotate(stack);
		// if last element is REV_ROTATE other stack,
		// exchange last for REV_ROTATE_A_B
		// else	
		ft_intlst_push_back(steps, (int)op);
	}
}
