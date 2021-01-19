/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:28:38 by svieira           #+#    #+#             */
/*   Updated: 2021/01/19 11:02:44 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_comp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s2[i] - s1[i]);
}

void	ft_sort(int ac, char **av)
{
	int		i;
	int		swaps;
	char	*buff;

	i = 1;
	swaps = 0;
	while (i < ac - 1)
	{
		if (ft_comp(av[i], av[i + 1]) < 0)
		{
			buff = av[i];
			av[i] = av[i + 1];
			av[i + 1] = buff;
			swaps++;
		}
		i++;
	}
	if (swaps > 0)
		ft_sort(ac, av);
}

void	ft_print(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	int i;

	if (ac <= 1)
		return (0);
	ft_sort(ac, av);
	i = 1;
	while (i < ac)
	{
		ft_print(av[i]);
		i++;
	}
	return (0);
}
