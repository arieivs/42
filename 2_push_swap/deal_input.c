/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:00:02 by svieira           #+#    #+#             */
/*   Updated: 2021/06/02 11:23:06 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_lstpush_back(t_list **lst, void *data)
{
	t_list *new_lst;

	new_lst = ft_lstnew(data);
	ft_lstadd_back(lst, new_lst); 
}

t_list	*create_stack(int ac, char **av)
{
	int	i;
	int	nb;
	t_list	*stack;
	
	i = 1;
	nb = ft_atoi(av[i++]);
	stack = ft_lstnew((void *)&nb);
	while (i < ac)
	{
		nb = av[i++];
		ft_lstpush_back(&stack, (void *)&nb);
	}
	return (stack);
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
