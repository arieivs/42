/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:22:04 by svieira           #+#    #+#             */
/*   Updated: 2020/12/16 11:36:01 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sum(int x, int y)
{
	return (x + y);
}

int	ft_sub(int x, int y)
{
	return (x - y);
}

int	ft_mult(int x, int y)
{
	return (x * y);
}

int	ft_div(int x, int y)
{
	if (y == 0)
		return (0);
	return (x / y);
}

int	ft_modulo(int x, int y)
{
	if (y == 0)
		return (0);
	return (x % y);
}
