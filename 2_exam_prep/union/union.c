/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:25:06 by svieira           #+#    #+#             */
/*   Updated: 2021/06/01 11:48:54 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	new_letter(char *str, int i, char letter)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (str[j] == letter)
			return (0);
		j++;
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		if (new_letter(s1, i, s1[i]))
			write(1, &s1[i], 1);
		i++;
	}
	j = 0;
	while (s2[j])
	{
		if (new_letter(s1, i, s2[j]) && new_letter(s2, j, s2[j]))
			write(1, &s2[j], 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union (av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
