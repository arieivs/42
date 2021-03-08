/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:49:00 by svieira           #+#    #+#             */
/*   Updated: 2021/03/08 23:52:31 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_line
{
	int				fd;
	char			*str;
	struct s_line	*next;
}				t_line;

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_memdel(void **ptr);
t_line			*ft_linenew(int fd);
t_line			*ft_linefind(t_line *list, int fd);
void			ft_linedel(t_line **list, int fd);
int				get_next_line(int fd, char **line);

#endif
