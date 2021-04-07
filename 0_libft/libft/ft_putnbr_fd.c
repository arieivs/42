/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:35:15 by svieira           #+#    #+#             */
/*   Updated: 2021/04/07 12:25:06 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnegnbr_fd(int n, int fd)
{
	if (n <= -10)
		ft_putnegnbr_fd(n / 10, fd);
	ft_putchar_fd(-(n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnegnbr_fd(n, fd);
	}
	else
		ft_putnegnbr_fd(-n, fd);
}
