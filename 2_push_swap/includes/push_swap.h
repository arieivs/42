/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:13:23 by svieira           #+#    #+#             */
/*   Updated: 2021/12/07 12:51:27 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_int_list
{
	int					nb;
	struct s_int_list	*next;
}				t_int_list;

// list utils
t_int_list	*ft_intlst_new(int nb);
void	ft_intlst_add_back(t_int_list **lst, t_int_list *new);
void	ft_intlst_push_back(t_int_list **lst, int nb);
void	ft_intlst_clear(t_int_list **lst, void (*del)(int));
void	ft_intlst_content_del(int nb);

// interface
int		invalid_input(int ac, char **av);
int		*create_arr(int ac, char **av);
int		duplicate_numbers(int arr_size, int *arr);
t_int_list	*create_stack(int ac, char **av);

// quick sort
void	quick_sort(int *arr, int start, int end);

// ops
void	swap(t_int_list **stack);
void	push(t_int_list **from, t_int_list **to);
void	rotate(t_int_list **stack);
void	reverse_rotate(t_int_list **stack);

// sort utils
int	is_sorted(t_int_list *stack);
int	get_index_min(t_int_list *stack);
int	get_index_max(t_int_list *stack);

// sorting algol
void	sort_3(t_int_list **stack);

#endif
