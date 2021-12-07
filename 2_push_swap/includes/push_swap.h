/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:13:23 by svieira           #+#    #+#             */
/*   Updated: 2021/12/07 15:13:23 by svieira          ###   ########.fr       */
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

typedef enum e_ops
{
	SWAP_A = 1,
	SWAP_B,
	SWAP_A_B,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_A_B,
	REV_ROTATE_A,
	REV_ROTATE_B,
	REV_ROTATE_A_B,
}	t_ops;

/*
** LIST UTILS
** Basic lists operations
*/
t_int_list	*ft_intlst_new(int nb);
void	ft_intlst_add_back(t_int_list **lst, t_int_list *new);
void	ft_intlst_push_back(t_int_list **lst, int nb);
void	ft_intlst_clear(t_int_list **lst, void (*del)(int));
void	ft_intlst_content_del(int nb);

/*
** INTERFACE
** Validating and parsing user input, printing the output
*/
int		invalid_input(int ac, char **av);
int		*create_arr(int ac, char **av);
int		duplicate_numbers(int arr_size, int *arr);
t_int_list	*create_stack(int ac, char **av);

// quick sort
//void	quick_sort(int *arr, int start, int end);

/*
** OPS
** Basic Push_Swap operations
*/
void	swap(t_int_list **stack);
void	push(t_int_list **from, t_int_list **to);
void	rotate(t_int_list **stack);
void	reverse_rotate(t_int_list **stack);
void	op(t_ops op, t_int_list **stack, t_int_list **sec_stack, t_int_list **steps);

/*
** SORT UTILS
** Helping functions for the sorting algorithms
*/
int	is_sorted(t_int_list *stack);
int	get_index_min(t_int_list *stack);
int	get_index_max(t_int_list *stack);

/*
** SORT ALGOL
** Sorting algorithm
*/
void	sort_3(t_int_list **stack, t_int_list **steps);

#endif
