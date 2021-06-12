/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:49:06 by svieira           #+#    #+#             */
/*   Updated: 2021/01/13 18:53:54 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tail_rec_fact(int n, int acc)
{
	if (n <= 1)
		return (acc);
	return (ft_tail_rec_fact(n - 1, n * acc));
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	return (ft_tail_rec_fact(nb, 1));
}
