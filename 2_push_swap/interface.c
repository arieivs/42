/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:00:02 by svieira           #+#    #+#             */
/*   Updated: 2021/12/06 22:59:57 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

int	non_digits_input(int ac, char **av)
{
	int	i;
	int	j;

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

int	invalid_numbers(int arr_size, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_size)
	{
		// if arr[i] bigger than max int
		// return (1);
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

