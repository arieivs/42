/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 09:44:26 by svieira           #+#    #+#             */
/*   Updated: 2021/01/22 10:29:52 by svieira          ###   ########.fr       */
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

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word;
	int		words;
	int		letters;
	char	**strs;

	i = 0;
	word = 0;
	words = words_count(str, charset);
	strs = (char **)malloc(sizeof(char*) * (words + 1));
	while (word < words)
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		letters = 0;
		while (str[i + letters] && !is_charset(str[i + letters], charset))
			letters++;
		strs[word] = (char *)malloc(sizeof(char) * (letters + 1));
		letters = 0;
		while (str[i] && !is_charset(str[i], charset))
			strs[word][letters++] = str[i++];
		strs[word++][letters] = 0;
	}
	strs[word] = 0;
	return (strs);
}
