/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:18:48 by svieira           #+#    #+#             */
/*   Updated: 2021/12/10 01:55:56 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

void	ft_intlst_delfirst(t_intlst **lst, void (*del)(int))
{
	t_intlst	*to_delete;

	if (!(*lst))
		return ;
	to_delete = *lst;
	*lst = (*lst)->next;
	del(to_delete->nb);
	free(to_delete);
}

void	ft_intlst_content_del(int nb)
{
	nb = 0;
}

t_intlst	*ft_intlst_last(t_intlst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
