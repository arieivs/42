/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:49:00 by svieira           #+#    #+#             */
/*   Updated: 2021/03/06 16:52:45 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strnew_empty(void);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen_chr(const char *s, char c);
char	*ft_strdup_chr(const char *s1, char c);
char	*ft_strjoin_chr(char *s1, char *s2, char c);
int		use_curr_line(char **line, char **curr_line);
int		read_file(int fd, char **line, char **curr_line);
int		get_next_line(int fd, char **line);

#endif
