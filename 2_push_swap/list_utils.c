/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:18:48 by svieira           #+#    #+#             */
/*   Updated: 2021/12/08 13:07:35 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_intlst	*ft_intlst_new(int nb)
{
	t_intlst	*list;

	list = (t_intlst *)malloc(sizeof(t_intlst));
	if (!list)
		return (NULL);
	list->nb = nb;
	list->next = 0;
	return (list);
}

void	ft_intlst_add_back(t_intlst **lst, t_intlst *new)
{
	t_intlst	*curr;

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

void	ft_intlst_push_back(t_intlst **lst, int nb)
{
	t_intlst	*new_lst;

	new_lst = ft_intlst_new(nb);
	ft_intlst_add_back(lst, new_lst);
}

void	ft_intlst_clear(t_intlst **lst, void (*del)(int))
{
	t_intlst	*to_delete;

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

int	ft_intlst_size(t_intlst *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
