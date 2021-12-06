/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:18:48 by svieira           #+#    #+#             */
/*   Updated: 2021/12/06 22:46:33 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_int_list	*ft_intlst_new(int nb)
{
	t_int_list	*list;

	list = (t_int_list *)malloc(sizeof(t_int_list));
	if (!list)
		return (NULL);
	list->nb = nb;
	list->next = 0;
	return (list);
}

void	ft_intlst_add_back(t_int_list **lst, t_int_list *new)
{
	t_int_list	*curr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	ft_intlst_push_back(t_int_list **lst, int nb)
{
	t_int_list *new_lst;

	new_lst = ft_intlst_new(nb);
	ft_intlst_add_back(lst, new_lst);
}

void	ft_intlst_clear(t_int_list **lst, void (*del)(int))
{
	t_int_list	*to_delete;

	while (*lst)
	{
		to_delete = *lst;
		*lst = (*lst)->next;
		del(to_delete->nb);
		free(to_delete);
	}
}

void	ft_intlst_content_del(int nb)
{
	nb = 0;
}
