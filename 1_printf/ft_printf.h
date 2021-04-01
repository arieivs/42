/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:16:40 by svieira           #+#    #+#             */
/*   Updated: 2021/04/01 15:56:32 by svieira          ###   ########.fr       */
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

t_fmt			*init_fmt(void);
int				str_include(char *str, char c);
int				parse(char *str, t_fmt *fmt, va_list ap);
int				print_fmt(t_fmt *fmt, va_list ap);
int				ft_printf(char *str, ...);

//d_print
int				d_print(t_fmt *fmt, va_list ap);

//d_print_utils
int		num_len(int n, char plus);
void	ft_putnbr_nosign(int n);

//from libft - to erase
//void	ft_putchar_fd(char c, int fd);
//void		ft_putnbr_fd(int n, int fd);

#endif
