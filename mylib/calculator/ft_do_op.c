/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:22:04 by svieira           #+#    #+#             */
/*   Updated: 2020/12/17 16:10:05 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char g_operators[5] = {'+', '-', '*', '/', '%'};
int (*g_maths[5])(int, int) = {&ft_sum, &ft_sub, &ft_mult, &ft_div, &ft_modulo};

int	ft_do_op(int x, int y, char op)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (op == g_operators[i])
			return (g_maths[i](x, y));
		i++;
	}
	return (0);
}
