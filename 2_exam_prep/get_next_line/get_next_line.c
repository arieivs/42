/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:02:13 by svieira           #+#    #+#             */
/*   Updated: 2021/11/04 22:13:54 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* 
 * prototype: char	*get_next_line(int fd);
 * allowed functions: read, free and malloc
 * return a line that has been read from fd
 * the line should be returned including the '\n' if it exists
 * if the buffer is empty, return NULL
 * in case of error, return NULL
 * compile with the flag -D BUFFER_SIZE=xx
 * no need to handle reading from different files
 */

static int	same_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	strlen(char *str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

static char	*concat(char *s1, char *s2)
{
	int		i;
	int		size1;
	int		size2;
	char	*s3;

	size1 = strlen(s1);
	size2 = strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[size1 + i] = s2[i];
		i++;
	}
	s3[size1 + i] = 0;
	free(s1);
	return (s3);
}

static char	*copy_next_line(char *line)
{
	int		i;
	int 	j;
	char	*next_line;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	j = 0;
	while (line[i + j])
		j++;
	next_line = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	while (line[i + j])
	{
		next_line[j] = line[i + j];
		j++;
	}
	next_line[j] = 0;
	free(line);
	return (next_line);
}

static char	*copy_curr_line(char *line)
{
	int		i;
	char	*curr_line;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	curr_line = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		curr_line[i] = line[i];
		i++;
	}
	curr_line[i] = line[i];
	curr_line[i++] = 0;
	return (curr_line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*next_line = NULL;
	int			rd;

	if (read(fd, 0, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!next_line)
	{
		next_line = (char *)malloc(sizeof(char));
		next_line[0] = 0;
	}
	while (same_line(next_line) && (rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd + 1] = 0;
		next_line = concat(next_line, buff);
	}
	free(buff);
	// when we leave the while loop, there are 3 scenarios
	// 1. error in read
	// 2. it read 0 characters
	// 2.1 EOF, we have to return NULL
	if (rd == -1 || (rd == 0 && strlen(next_line) == 0))
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	// 2.2 we have the last line to return and reached EOF
	if (rd == 0)
	{
		line = copy_curr_line(next_line);
		free(next_line);
		next_line = NULL;
		return (line); 
	}
	// 3. there's a \n in line
	line = copy_curr_line(next_line);
	next_line = copy_next_line(next_line);
	return (line);
}

