/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:25:51 by svieira           #+#    #+#             */
/*   Updated: 2021/02/22 16:36:27 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*to_delete;

	while (begin_list)
	{
		to_delete = begin_list;
		begin_list = begin_list->next;
		free_fct(to_delete->data);
		free(to_delete);
	}
}
