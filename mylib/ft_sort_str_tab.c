/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:21:32 by svieira           #+#    #+#             */
/*   Updated: 2020/12/16 14:51:30 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char*, char*))
{
	int		i;
	int		swaps;
	char	*buff;

	i = 0;
	swaps = 0;
	while (tab[i + 1])
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			buff = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buff;
			swaps++;
		}
		i++;
	}
	if (swaps != 0)
		ft_advanced_sort_string_tab(tab, cmp);
}
