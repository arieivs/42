/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:13:23 by svieira           #+#    #+#             */
/*   Updated: 2021/12/08 13:09:11 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_intlst
{
	int				nb;
	struct s_intlst	*next;
}				t_intlst;

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
t_intlst	*ft_intlst_new(int nb);
void		ft_intlst_add_back(t_intlst **lst, t_intlst *new);
void		ft_intlst_push_back(t_intlst **lst, int nb);
void		ft_intlst_clear(t_intlst **lst, void (*del)(int));
void		ft_intlst_content_del(int nb);
int			ft_intlst_size(t_intlst *lst);

/*
** INTERFACE
** Validating and parsing user input, printing the output
*/
int			invalid_input(int ac, char **av);
int			*create_arr(int ac, char **av);
int			duplicate_numbers(int arr_size, int *arr);
t_intlst	*create_stack(int ac, char **av);
void		print_instructions(t_intlst *steps);

// quick sort
//void	quick_sort(int *arr, int start, int end);

/*
** OPS
** Basic Push_Swap operations
*/
void		swap(t_intlst **stack);
void		push(t_intlst **from, t_intlst **to);
void		rotate(t_intlst **stack);
void		reverse_rotate(t_intlst **stack);
void		op(t_ops op, t_intlst **stk, t_intlst **sec_stk, t_intlst **steps);

/*
** SORT UTILS
** Helping functions for the sorting algorithms
*/
int			is_sorted(t_intlst *stack);
int			get_index_min(t_intlst *stack);
int			get_index_max(t_intlst *stack);

/*
** SORT ALGOL
** Sorting algorithm
*/
void		sort_3(t_intlst **stack, t_intlst **steps);
void		sort_5(t_intlst **stack_a, t_intlst **stack_b, t_intlst ** steps);
void		sort_stack(t_intlst **stack_a, t_intlst **steps);

#endif
