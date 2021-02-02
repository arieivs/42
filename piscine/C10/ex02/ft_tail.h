/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:39:18 by svieira           #+#    #+#             */
/*   Updated: 2021/02/02 12:26:33 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>

int		is_signal(char c);
int		is_number(char c);
int		ft_atoi(char *str);
void	put_strerr(char *str);
int		get_size(char *path, int buff_size);
void	rd_stdin_wr(int fd_dest, int buff_size);
void	o_rd_wr_c(char *path_src, int fd_dest, int head_size, int tail_size);
void	display(int ac, char **av);
void	write_file(int ac, char **av, int i_op, int op);
int		is_op(char *str);
int		invalid_input(int ac, char **av);

#endif
