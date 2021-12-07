/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:00:02 by svieira           #+#    #+#             */
/*   Updated: 2021/12/07 15:32:26 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

// move this to libft:
long	ft_atol(const char *str)
{
	int		i;
	int		signal;
	long	nb;

	i = 0;
	signal = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * signal);
}

int	invalid_input(int ac, char **av)
{
	int		i;
	int		j;
	long	nb;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (ft_strlen(av[i]) == 0)
			return (1);
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	*create_arr(int ac, char **av)
{
	int i;
	int	*arr;

	i = 1;
	arr = (int *)malloc(sizeof(int) * (ac - 1));
	while (i < ac)
	{
		arr[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (arr);
}

// for now it depends on the array, change if I don't use it
int	duplicate_numbers(int arr_size, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_int_list	*create_stack(int ac, char **av)
{
	int			i;
	int			nb;
	t_int_list	*stack;
	
	i = 1;
	nb = ft_atoi(av[i++]);
	stack = ft_intlst_new(nb);
	while (i < ac)
	{
		nb = ft_atoi(av[i++]);
		ft_intlst_push_back(&stack, nb);
	}
	return (stack);
}

void	print_instructions(t_int_list *steps)
{
	while (steps)
	{
		if (steps->nb == SWAP_A)
			write(1, "sa\n", 3);
		else if (steps->nb == SWAP_B)
			write(1, "sb\n", 3);
		else if (steps->nb == SWAP_A_B)
			write(1, "ss\n", 3);
		else if (steps->nb == PUSH_A)
			write(1, "pa\n", 3);
		else if (steps->nb == PUSH_B)
			write(1, "pb\n", 3);
		else if (steps->nb == ROTATE_A)
			write(1, "ra\n", 3);
		else if (steps->nb == ROTATE_B)
			write(1, "rb\n", 3);
		else if (steps->nb == ROTATE_A_B)
			write(1, "rr\n", 3);
		else if (steps->nb == REV_ROTATE_A)
			write(1, "rra\n", 4);
		else if (steps->nb == REV_ROTATE_B)
			write(1, "rrb\n", 4);
		else if (steps->nb == REV_ROTATE_A_B)
			write(1, "rrr\n", 4);
		steps = steps->next;
	}
}
