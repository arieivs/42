/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:59:07 by svieira           #+#    #+#             */
/*   Updated: 2021/01/19 20:10:27 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putaddr(void *addr, int i)
{
	int				j;
	unsigned int	mem;
	char			memory[16];

	j = 0;
	mem = (unsigned int)&addr[i];
	while (mem > 0)
	{
		memory[j] = "012345689abcdef"[mem % 16];
		mem /= 16;
		j++;
	}
	while (j < 16)
	{
		memory[j] = '0';
		j++;
	}
	j--;
	while (j >= 0)
	{
		write(1, &memory[j], 1);
		j--;
	}
	write(1, ": ", 2);
}

void	ft_puthexa(void *addr, unsigned int i, unsigned int size)
{
	unsigned int	stop;
	int				dec;
	char			*str;

	stop = i + 16;
	str = (char *)addr;
	while (i < stop && i < size)
	{
		dec = str[i];
		if (dec < 0)
			dec += 256;
		write(1, &"0123456789abcdef"[dec / 16], 1);
		write(1, &"0123456789abcdef"[dec % 16], 1);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < stop)
	{
		write(1, " ", 1);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	ft_putstr(void *addr, unsigned int i, unsigned int size)
{
	unsigned int	stop;
	char			*str;

	stop = i + 16;
	str = (char *)addr;
	while (i < stop && i < size)
	{
		if (str[i] <= 31 || str[i] >= 127)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int line;
	int lines;

	line = 0;
	lines = size % 16 ? size / 16 + 1 : size / 16;
	while (line < lines)
	{
		ft_putaddr(addr, line * 16);
		ft_puthexa(addr, line * 16, size);
		ft_putstr(addr, line * 16, size);
		line++;
	}
	return (addr);
}
