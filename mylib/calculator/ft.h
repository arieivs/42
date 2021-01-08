/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:27:40 by svieira           #+#    #+#             */
/*   Updated: 2020/12/16 11:31:18 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		ft_atoi(char *str);
int		ft_valid_op(int y, char *operator);
int		ft_sum(int x, int y);
int		ft_sub(int x, int y);
int		ft_mult(int x, int y);
int		ft_div(int x, int y);
int		ft_modulo(int x, int y);
int		ft_do_op(int x, int y, char op);
void	ft_putnbr(int nb);

#endif
