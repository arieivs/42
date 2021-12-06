/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:13:23 by svieira           #+#    #+#             */
/*   Updated: 2021/12/06 19:13:23 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

// interface
int		non_digits_input(int ac, char **av);
int		*create_arr(int ac, char **av);
int		invalid_numbers(int arr_size, int *arr);
void	ft_lstpush_back(t_list **lst, void *data);
t_list	*create_stack(int ac, char **av);

// quick sort
void	quick_sort(int *arr, int start, int end);

// ops
void	swap(t_list **stack);
void	push(t_list **from, t_list **to);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

// cleaning the house
void	ft_del(void *content);

#endif
