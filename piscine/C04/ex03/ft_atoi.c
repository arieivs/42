/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:26:33 by svieira           #+#    #+#             */
/*   Updated: 2021/01/09 18:44:57 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_is_signal(char c)
{
	return (c == '+' || c == '-');
}

int	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int i;
	int signal;
	int nb;

	i = 0;
	signal = 1;
	nb = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	while (str[i] && ft_is_signal(str[i]))
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] && ft_is_number(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (signal * nb);
}
