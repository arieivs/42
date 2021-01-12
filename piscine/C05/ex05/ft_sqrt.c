/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:03:13 by svieira           #+#    #+#             */
/*   Updated: 2021/01/12 19:32:29 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_sqrt(int nb, int guess)
{
	int next_guess;

	next_guess = (nb / guess + guess) / 2;
	if (guess == next_guess)
		return (guess);
	return (ft_find_sqrt(nb, next_guess));
}

int	ft_sqrt(int nb)
{
	int sqrt;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	sqrt = ft_find_sqrt(nb, nb / 2);
	if (sqrt * sqrt == nb)
		return (sqrt);
	else
		return (0);
}
