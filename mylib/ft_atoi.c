/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:36:29 by svieira           #+#    #+#             */
/*   Updated: 2020/12/14 18:07:31 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_signal(char c)
{
	return (c == '+' || c == '-');
}

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int i;
	int neg_signals;
	int nb;

	i = 0;
	neg_signals = 0;
	nb = 0;
	while (str[i] && is_space(str[i]))
		i++;
	while (str[i] && is_signal(str[i]))
	{
		if (str[i] == '-')
			neg_signals += 1;
		i++;
	}
	while (str[i] && is_number(str[i]))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (neg_signals % 2 == 1)
		nb *= -1;
	return (nb);
}
