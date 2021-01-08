/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:22:44 by svieira           #+#    #+#             */
/*   Updated: 2020/12/03 12:05:45 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alphanumeric(char c)
{
	if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122)
	{
		return (0);
	}
	return (1);
}

int		ft_is_alphalow(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int		ft_is_alphaup(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_alphanumeric(str[i - 1]) && ft_is_alphalow(str[i]))
		{
			str[i] -= 32;
		}
		else if (ft_is_alphanumeric(str[i - 1]) && ft_is_alphaup(str[i]))
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
