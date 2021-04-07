/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:06:15 by svieira           #+#    #+#             */
/*   Updated: 2021/04/07 12:25:55 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == 0 || str[i + 1] == c))
			words++;
		i++;
	}
	return (words);
}

static char	**fill_arr(const char *str, char c, int words, char **strs)
{
	int	i;
	int	word;
	int	letters;

	i = 0;
	word = 0;
	while (word < words)
	{
		while (str[i] && str[i] == c)
			i++;
		letters = 0;
		while (str[i + letters] && str[i + letters] != c)
			letters++;
		strs[word] = (char *)malloc(sizeof(char) * (letters + 1));
		if (!strs[word])
			return (NULL);
		letters = 0;
		while (str[i] && str[i] != c)
			strs[word][letters++] = str[i++];
		strs[word++][letters] = 0;
	}
	strs[word] = 0;
	return (strs);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**strs;

	words = words_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (words + 1));
	if (!strs)
		return (NULL);
	fill_arr(s, c, words, strs);
	return (strs);
}
