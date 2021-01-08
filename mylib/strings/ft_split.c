/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 11:57:44 by svieira           #+#    #+#             */
/*   Updated: 2021/01/08 20:54:15 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!ft_is_sep(str[i], charset))
		{
			if (str[i + 1] == '\0' || ft_is_sep(str[i + 1], charset))
				words++;
		}
		i++;
	}
	return (words);
}

char	**ft_fill_arr(char *str, char *charset, char **arr, int words)
{
	int	i;
	int	j;
	int	k;
	int	w;

	i = 0;
	j = 0;
	k = 0;
	w = 0;
	while (w < words)
	{
		j = 0;
		k = 0;
		while (str[i] && ft_is_sep(str[i], charset))
			i++;
		while (str[i + k] && !ft_is_sep(str[i + k], charset))
			k++;
		arr[w] = (char*)malloc(sizeof(char*) * (k + 1));
		while (str[i] && !ft_is_sep(str[i], charset))
			arr[w][j++] = str[i++];
		arr[w][j] = '\0';
		w++;
	}
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**arr;

	words = ft_count_words(str, charset);
	arr = (char**)malloc(sizeof(char*) * (words + 1));
	arr = ft_fill_arr(str, charset, arr, words);
	arr[words] = 0;
	return (arr);
}
