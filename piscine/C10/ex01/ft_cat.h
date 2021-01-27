/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:32:04 by svieira           #+#    #+#             */
/*   Updated: 2021/01/27 11:34:04 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int		is_op(char *str);
void	open_read_write(char *path_src, int fd_dest, int buff_size);
void	display_files(int ac, char **av);
void	write_file(int ac, char **av, int i_op, int op);

#endif
