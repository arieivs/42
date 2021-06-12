/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:44:57 by svieira           #+#    #+#             */
/*   Updated: 2021/02/08 17:42:03 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_list;

	new_list = ft_create_elem(data);
	new_list->next = *begin_list;
	*begin_list = new_list;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	int		i;

	if (size == 0)
		return (0);
	list = ft_create_elem((void *)strs[0]);
	i = 1;
	while (i < size)
	{
		ft_list_push_front(&list, (void *)strs[i]);
		i++;
	}
	return (list);
}
