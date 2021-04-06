/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:59:01 by svieira           #+#    #+#             */
/*   Updated: 2021/04/06 12:51:29 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	n_print(va_list ap, int printed)
{
	int	*n;

	n = (int *)va_arg(ap, int *);
	*n = printed;
}

void	nh_print(va_list ap, int printed)
{
	short int	*n;

	n = (short int *)va_arg(ap, int *);
	*n = (short int)printed;
}
