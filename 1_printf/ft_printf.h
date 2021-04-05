/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:16:40 by svieira           #+#    #+#             */
/*   Updated: 2021/04/05 15:55:08 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_fmt
{
	int		left_align;
	char	fill;
	char	plus;
	int		hash;
	int		width;
	int		point;
	int		precision;
	char	conv;
}				t_fmt;

//ft_printf
t_fmt			*init_fmt(void);
int				print_fmt(t_fmt *fmt, va_list ap);
int				ft_printf(const char *str, ...);

//parse
int				str_include(char *str, char c);
int				parse(const char *str, t_fmt *fmt, va_list ap);

//c_print
int				c_print(t_fmt *fmt, va_list ap);

//s_print
int				s_print(t_fmt *fmt, va_list ap);

//di_print
int				d_print(t_fmt *fmt, va_list ap);
//ux_print
int				ux_print(t_fmt *fmt, va_list ap);
//diux_print_utils
int				calc_width(int n_len, int width, int preci);
void			ft_putnbr_nosign(int n);
void			ft_put_unbr(unsigned int n);
void			ft_put_xnbr(unsigned int n, char *base);

//p_print
int				p_print(t_fmt *fmt, va_list ap);
//p_print_utils
void			ft_put_xl(unsigned long n, char *base);

#endif
