/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:59:01 by svieira           #+#    #+#             */
/*   Updated: 2021/04/06 16:21:35 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	n_print(va_list ap, int printed, char hh)
{
	int		*n;
	char	c;

	n = (int *)va_arg(ap, int *);
	*n = printed;
	if (hh)
	{
		c = (char)(*n);
		*n = (int)c;
	}
}

void	nh_print(va_list ap, int printed)
{
	short int	*n;

	n = (short int *)va_arg(ap, int *);
	*n = (short int)printed;
}

void	nll_print(va_list ap, int printed)
{
	long long int	*n;

	n = (long long int *)va_arg(ap, long long int *);
	*n = (long long int)printed;
}
