/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:52:35 by svieira           #+#    #+#             */
/*   Updated: 2021/04/09 10:56:04 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_xl(unsigned long n, char *base)
{
	if (n >= 16)
		ft_put_xl(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}
