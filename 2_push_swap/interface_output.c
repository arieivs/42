/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:46:03 by svieira           #+#    #+#             */
/*   Updated: 2021/12/08 20:05:14 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	print_instructions_router(int op)
{
	if (op == SWAP_A)
		write(1, "sa\n", 3);
	else if (op == SWAP_B)
		write(1, "sb\n", 3);
	else if (op == SWAP_A_B)
		write(1, "ss\n", 3);
	else if (op == PUSH_A)
		write(1, "pa\n", 3);
	else if (op == PUSH_B)
		write(1, "pb\n", 3);
	else if (op == ROTATE_A)
		write(1, "ra\n", 3);
	else if (op == ROTATE_B)
		write(1, "rb\n", 3);
	else if (op == ROTATE_A_B)
		write(1, "rr\n", 3);
	else if (op == REV_ROTATE_A)
		write(1, "rra\n", 4);
	else if (op == REV_ROTATE_B)
		write(1, "rrb\n", 4);
	else if (op == REV_ROTATE_A_B)
		write(1, "rrr\n", 4);
}

void	print_instructions(t_intlst *steps)
{
	while (steps)
	{
		print_instructions_router(steps->nb);
		steps = steps->next;
	}
}

void	print_stack(t_intlst *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->nb, 1);
		write(1, " ", 1);
		stack = stack->next;
	}
	write(1, "\n", 1);
}
