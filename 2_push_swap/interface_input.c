/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:53:32 by svieira           #+#    #+#             */
/*   Updated: 2021/12/08 15:53:51 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// I should move this to libft
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

static int	valid_characters(char *str)
{
	int	i;
	int	has_nb;

	i = 0;
	has_nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		has_nb = 1;
		i++;
	}
	return (has_nb);
}

static int	duplicate_number(int nb, t_intlst *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nb == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	validate_input_core(char *str, t_intlst **stack)
{
	long	nb;

	if (ft_strlen(str) == 0)
		return (0);
	if (!valid_characters(str))
		return (0);
	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	if (duplicate_number((int)nb, *stack))
		return (0);
	ft_intlst_push_back(stack, (int)nb);
	return (1);
}

int	validate_input_push_stack(int ac, char **av, t_intlst **stack)
{
	int		i;
	char	**arr;

	i = 0;
	if (ac == 2)
	{
		arr = ft_split(av[1], ' ');
		while (arr[i])
		{
			if (!validate_input_core(arr[i++], stack))
			{
				free(arr);
				return (0);
			}
		}
		free(arr);
		return (1);
	}
	while (i + 1 < ac)
	{
		if (!validate_input_core(av[i + 1], stack))
			return (0);
		i++;
	}
	return (1);
}

/*int	*create_arr(int ac, char **av)
{
	int	i;
	int	*arr;

	i = 1;
	arr = (int *)malloc(sizeof(int) * (ac - 1));
	while (i < ac)
	{
		arr[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (arr);
}*/
