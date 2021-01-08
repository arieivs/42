/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:51:56 by svieira           #+#    #+#             */
/*   Updated: 2020/11/29 19:21:51 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int index;
	int swaps;
	int helper;

	index = 0;
	swaps = 0;
	while (index < (size - 1))
	{
		if (tab[index] > tab[index + 1])
		{
			helper = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = helper;
			swaps++;
		}
		index++;
	}
	if (swaps != 0)
	{
		ft_sort_int_tab(tab, size);
	}
}
