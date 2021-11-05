/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:36:39 by svieira           #+#    #+#             */
/*   Updated: 2021/11/05 18:45:33 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
 * programme
 * takes two strings
 * displays without doubles the characters present in both strings
 * followed by \n
 * if it doesn't receive two args, should display a \n
 */

static int	str_has_char(char *str, char c, int i)
{
	int	j;

	j = 0;
	if (i < 0)
	{
		while (str[j])
		{
			if (str[j] == c)
				return (1);
			j++;
		}
		return (0);
	}
	while (str[j] && j < i)
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

void	inter(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!str_has_char(s1, s1[i], i) && str_has_char(s2, s1[i], -1))
			write(1, &s1[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
