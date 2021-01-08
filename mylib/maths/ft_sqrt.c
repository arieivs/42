/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:54:44 by svieira           #+#    #+#             */
/*   Updated: 2020/12/08 15:15:48 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_next_interval(int try, int prev, int nb)
{
	if (try * try == nb)
		return (try);
	if (try == prev)
		return (0);
	return (ft_next_interval(((try + (nb / try)) / 2), try, nb));
}

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	return (ft_next_interval((nb / 2), 1, nb));
}
