/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:13:23 by svieira           #+#    #+#             */
/*   Updated: 2021/12/10 13:24:11 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# define RETURN_VALUE 0
# define RETURN_INDEX 1
# define THRESHOLD 20

typedef struct s_intlst
{
	int				nb;
	struct s_intlst	*next;
}				t_intlst;

typedef struct s_limits
{
	int	a_part_sorted;
	int	abs_min;
	int	min;
	int	i_min;
	int	max;
	int	i_max;
	int	mean;
	int	size;
}				t_limits;

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
void		ft_intlst_push_right_order(t_intlst **lst, int nb);
int			ft_intlst_size(t_intlst *lst);
void		ft_intlst_clear(t_intlst **lst, void (*del)(int));
void		ft_intlst_delfirst(t_intlst **lst, void (*del)(int));
void		ft_intlst_content_del(int nb);
t_intlst	*ft_intlst_last(t_intlst *lst);

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
int			get_min(t_intlst *stack, int return_what);
int			get_max(t_intlst *stack, int return_what);
int			get_mean(t_intlst *stack);
t_intlst	*get_min_mean_max(t_intlst *stack);

/*
** SORT ALGOL
** Sorting algorithm
*/
void		sort_3(t_intlst **stack, t_intlst **steps);
void		sort_5(t_intlst **s_a, t_intlst **s_b, t_intlst **st);
void		sort_big(t_intlst **a, t_intlst **b, t_intlst **lm, t_intlst **st);
void		sort_stack(t_intlst **stack_a, t_intlst **steps);

/*
** INTERFACE INPUT
** Validating and parsing user input
*/
int			validate_input_push_stack(int ac, char **av, t_intlst **stack);

/*
 * INTERFACE OUTPUT
 * Printing output (instructions)
 */
void		print_instructions(t_intlst *steps);
void		print_stack(t_intlst *stack);	

#endif
