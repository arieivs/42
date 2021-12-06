/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:00:02 by svieira           #+#    #+#             */
/*   Updated: 2021/12/06 22:10:04 by svieira          ###   ########.fr       */
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

// move this to list_utils or libft:
void	ft_lstpush_back(t_list **lst, void *data)
{
	t_list *new_lst;

	new_lst = ft_lstnew(data);
	ft_lstadd_back(lst, new_lst); 
}

void create_stack(int ac, char **av, t_list **stack)
{
	int	i;
	int	nb;
	//t_list	*stack;
	
	i = 1;
	nb = (int)malloc(sizeof(int));
	nb = ft_atoi(av[i++]);
	printf("adding %d\n", nb);
	*stack = ft_lstnew((void *)&nb);
	printf("added %d\n", *(int *)(*stack)->content);
	while (i < ac)
	{
		nb = ft_atoi(av[i++]);
		printf("adding %d\n", nb);
		ft_lstadd_back(stack, ft_lstnew((void *)&nb));
		//ft_lstpush_back(&stack, (void *)&nb);
	}
	printf("added %d %d\n", *(int *)(*stack)->content, *(int *)(*stack)->next->content);
}

