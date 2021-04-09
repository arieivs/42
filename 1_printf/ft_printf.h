/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:16:40 by svieira           #+#    #+#             */
/*   Updated: 2021/04/09 11:01:24 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include "libft/libft.h"

typedef struct s_fmt
{
	int		left_align;
	char	fill;
	char	plus;
	int		hash;
	int		width;
	int		point;
	int		precision;
	char	size;
	char	conv;
}				t_fmt;

t_fmt			*init_fmt(void);
int				str_include(char *str, char c);
int				print_fmt(t_fmt *fmt, va_list ap, int printed);
int				ft_printf(const char *str, ...);
int				parse(const char *str, t_fmt *fmt, va_list ap);
int				c_print(t_fmt *fmt, va_list ap);
int				s_print(t_fmt *fmt, va_list ap);
int				di_print(t_fmt *fmt, va_list ap);
int				ux_print(t_fmt *fmt, va_list ap);
int				calc_width(int n_len, int width, int preci);
void			ft_putnbr_nosign(int n);
void			ft_put_unbr(unsigned int n);
void			ft_put_xnbr(unsigned int n, char *base);
int				dih_print(t_fmt *fmt, va_list ap);
int				uxh_print(t_fmt *fmt, va_list ap);
int				dil_print(t_fmt *fmt, va_list ap);
int				uxl_print(t_fmt *fmt, va_list ap);
void			ft_put_lnbr_nosign(long int n);
void			ft_put_ulnbr(unsigned long int n);
void			ft_put_xlnbr(unsigned long int n, char *base);
int				dill_print(t_fmt *fmt, va_list ap);
int				uxll_print(t_fmt *fmt, va_list ap);
void			ft_put_llnbr_nosign(long long int n);
void			ft_put_ullnbr(unsigned long long int n);
void			ft_put_xllnbr(unsigned long long int n, char *base);
int				p_print(t_fmt *fmt, va_list ap);
void			ft_put_xl(unsigned long n, char *base);
void			n_print(va_list ap, int printed);
void			nhh_print(va_list ap, int printed);
void			nh_print(va_list ap, int printed);
void			nl_print(va_list ap, int printed);
void			nll_print(va_list ap, int printed);
int				f_print(t_fmt *fmt, va_list ap);
long int		ft_recursive_power(int nb, int power);
int				fnum_len(double f, t_fmt *fmt);
void			ft_putfloat_nosign(double f, int precision, int hash);

#endif
