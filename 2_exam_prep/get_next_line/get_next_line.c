/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:02:13 by svieira           #+#    #+#             */
/*   Updated: 2021/06/01 13:04:56 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Differences from project GNL:
 * fd = 0
 * no fd changes between function calls
 * no buffer size variable
 */

int	get_next_line(char **line)
{
	static char	*cur_line = NULL;
	char	*buff;

	if (!line)
		return (-1);
	if (!cur_line)
	{
		cur_line = (char *)malloc(sizeof(char));
		cur_line[0] = 0;
	}
	// buffer size was chosen very randomly
	buff = (char *)malloc(sizeof(char) * 1024);



