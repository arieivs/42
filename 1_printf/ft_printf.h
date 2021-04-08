/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:16:40 by svieira           #+#    #+#             */
/*   Updated: 2021/04/08 23:50:34 by svieira          ###   ########.fr       */
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

//ft_printf
t_fmt			*init_fmt(void);
int				str_include(char *str, char c);
int				print_fmt(t_fmt *fmt, va_list ap, int printed);
int				ft_printf(const char *str, ...);

//parse
int				parse(const char *str, t_fmt *fmt, va_list ap);

//c_print
int				c_print(t_fmt *fmt, va_list ap);

//s_print
int				s_print(t_fmt *fmt, va_list ap);

//di_print
int				di_print(t_fmt *fmt, va_list ap);
//ux_print
int				ux_print(t_fmt *fmt, va_list ap);
//diux_print_utils
int				calc_width(int n_len, int width, int preci);
void			ft_putnbr_nosign(int n);
void			ft_put_unbr(unsigned int n);
void			ft_put_xnbr(unsigned int n, char *base);

//dih_print
int				dih_print(t_fmt *fmt, va_list ap);
//uxh_print
int				uxh_print(t_fmt *fmt, va_list ap);

//dil_print
int				dil_print(t_fmt *fmt, va_list ap);
//uxl_print
int				uxl_print(t_fmt *fmt, va_list ap);
//diuxl_print_utils
void			ft_put_lnbr_nosign(long int n);
void			ft_put_ulnbr(unsigned long int n);
void			ft_put_xlnbr(unsigned long int n, char *base);

//dill_print
int				dill_print(t_fmt *fmt, va_list ap);
//uxll_print
int				uxll_print(t_fmt *fmt, va_list ap);
//diuxll_print_utils
void			ft_put_llnbr_nosign(long long int n);
void			ft_put_ullnbr(unsigned long long int n);
void			ft_put_xllnbr(unsigned long long int n, char *base);

//p_print
int				p_print(t_fmt *fmt, va_list ap);
//p_print_utils
void			ft_put_xl(unsigned long n, char *base);

//n_print
void			n_print(va_list ap, int printed);
void			nhh_print(va_list ap, int printed);
void			nh_print(va_list ap, int printed);
void			nl_print(va_list ap, int printed);
void			nll_print(va_list ap, int printed);

//f_print
int				f_print(t_fmt *fmt, va_list ap);
long int		ft_recursive_power(int nb, int power);
//f_print_utils
int				fnum_len(double f, t_fmt *fmt);
void			ft_putfloat_nosign(double f, int precision, int hash);

#endif
