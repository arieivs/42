/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:48:15 by svieira           #+#    #+#             */
/*   Updated: 2020/12/16 11:37:12 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_valid_op(int y, char *operator)
{
	int i;

	i = 0;
	while (operator[i])
		i++;
	if (i != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (y == 0)
	{
		if (operator[0] == '/')
		{
			write(1, "Stop : division by zero\n", 24);
			return (0);
		}
		if (operator[0] == '%')
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (0);
		}
	}
	return (1);
}
