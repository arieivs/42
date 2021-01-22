/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 09:44:26 by svieira           #+#    #+#             */
/*   Updated: 2021/01/22 11:12:38 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		words_count(char *str, char *charset)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset) &&
			(str[i + 1] == 0 || is_charset(str[i + 1], charset)))
			words++;
		i++;
	}
	return (words);
}

char	**ft_fill_arr(char *str, char *charset, int words, char **strs)
{
	int i;
	int word;
	int letters;

	i = 0;
	word = 0;
	while (word < words)
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		letters = 0;
		while (str[i + letters] && !is_charset(str[i + letters], charset))
			letters++;
		strs[word] = (char *)malloc(sizeof(char) * (letters + 1));
		if (!strs[word])
			return (NULL);
		letters = 0;
		while (str[i] && !is_charset(str[i], charset))
			strs[word][letters++] = str[i++];
		strs[word++][letters] = 0;
	}
	strs[word] = 0;
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**strs;

	words = words_count(str, charset);
	strs = (char **)malloc(sizeof(char*) * (words + 1));
	if (!strs)
		return (NULL);
	ft_fill_arr(str, charset, words, strs);
	return (strs);
}
