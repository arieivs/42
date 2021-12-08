/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:23:32 by svieira           #+#    #+#             */
/*   Updated: 2021/12/08 20:06:22 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_intlst	*stack_a;
	t_intlst	*steps;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	if (!validate_input_push_stack(ac, av, &stack_a))
	{
		ft_intlst_clear(&stack_a, &ft_intlst_content_del);
		write(2, "Error\n", 6);
		return (0);
	}
	if (is_sorted(stack_a))
	{
		ft_intlst_clear(&stack_a, &ft_intlst_content_del);
		return (0);
	}
	steps = NULL;
	sort_stack(&stack_a, &steps);
	print_instructions(steps);
	ft_intlst_clear(&stack_a, &ft_intlst_content_del);
	ft_intlst_clear(&steps, &ft_intlst_content_del);
	return (0);
}
