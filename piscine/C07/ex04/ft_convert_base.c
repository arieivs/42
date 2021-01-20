/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:50:06 by svieira           #+#    #+#             */
/*   Updated: 2021/01/20 20:03:55 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_is_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *nbr, char *base_from)
{
	int i;
	int signal;
	int nb;
	int base_len;
	int index;

	i = 0;
	signal = 1;
	nb = 0;
	base_len = ft_strlen(base_from);
	while (nbr[i] && ft_is_space(nbr[i]))
		i++;
	while (nbr[i] && (nbr[i] == '+' || nbr[i] == '-'))
	{
		if (nbr[i] == '-')
			signal *= -1;
		i++;
	}
	while (nbr[i] && (index = ft_is_base(nbr[i], base_from)))
	{
		nb = nb * base_len + index;
		i++;
	}
	return (nb * signal);
}
