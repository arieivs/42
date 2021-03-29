/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:16:40 by svieira           #+#    #+#             */
/*   Updated: 2021/03/29 19:41:09 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_fmt
{
	char	plus;
	int		left_align;
	char	fill;
	int		width;
	int		point;
	int		precision;
	char	conv;
}				t_fmt;

t_fmt			*init_fmt(void);
int				parse(char *str, t_fmt *fmt, va_list ap);
int				print_fmt(t_fmt *fmt, va_list ap);

#endif
