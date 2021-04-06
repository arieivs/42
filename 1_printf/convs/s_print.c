/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:38 by svieira           #+#    #+#             */
/*   Updated: 2021/04/04 17:00:43 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_putstr_untiln(char *s, int n)
{
	int i;

	i = 0;
	while (s[i] && i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
}

static void	s_actual_print(char *s, t_fmt *fmt, int extra_width)
{
	if (!fmt->left_align)
	{
		while (extra_width-- > 0)
			write(1, " ", 1);
	}
	if (fmt->point)
		ft_putstr_untiln(s, fmt->precision);
	else
		ft_putstr_fd(s, 1);
	if (fmt->left_align)
	{
		while (extra_width-- > 0)
			write(1, " ", 1);
	}
}

int			s_print(t_fmt *fmt, va_list ap)
{
	char	*s;
	int		s_len;
	int		real_len;
	int		extra_width;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	s_len = ft_strlen(s);
	real_len = s_len;
	if (fmt->point && fmt->precision < s_len)
		real_len = fmt->precision;
	extra_width = 0;
	if (fmt->width > real_len)
		extra_width = fmt->width - real_len;
	s_actual_print(s, fmt, extra_width);
	return (extra_width + real_len);
}
