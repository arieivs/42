/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:01:56 by svieira           #+#    #+#             */
/*   Updated: 2021/02/05 21:05:07 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new_list;
	t_list *curr_list;

	new_list = ft_create_elem(data);
	if (*begin_list == 0)
		*begin_list = new_list;
	else
	{
		curr_list = *begin_list;
		while (curr_list->next)
			curr_list = curr_list->next;
		curr_list->next = new_list;
	}
}
