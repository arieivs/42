/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:01:12 by svieira           #+#    #+#             */
/*   Updated: 2020/11/27 16:45:22 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int index;
	int helper[size];

	index = 0;
	while (index < size)
	{
		helper[index] = tab[size - 1 - index];
		index++;
	}
	index = 0;
	while (index < size)
	{
		tab[index] = helper[index];
		index++;
	}
}
