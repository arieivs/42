/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:22:55 by svieira           #+#    #+#             */
/*   Updated: 2021/06/04 17:09:27 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* QUICK SORT
 * Iterate over the stack A (ra's)
 * if elememt is smaller than average, push to b (pb)
 * right now we have: upper half in A, lower half in B
 * Iterate over the stack B (rb's)
 * if element is bigger than average in B, push to A (pa)
 * if element is the minimum in the whole B stack, push to bottom of A (pa + ra)
 * to think: how do I keep track of the minimum? I could of course, order an array with the same content of the stack to compare... but... I mean...
 */

/*int	arr_mean(int *arr, int length)
{
	int i;
	int	mean;

	i = 0
	while (i < length)
		mean += arr[i++];
	mean /= length;
	return (mean);
}*/

int	lst_mean(t_list *list)
{
	int	mean;

	mean = 0;
	while (list)
	{
		mean += *(int *)list->content;
		list = list->next;
	}
	return (mean);
}

int	b_to_top_bot_a(t_list **stack_a, t_list **stack_b, int *arr, int *min)
{
	int	mean_b;
	int	moves;

	moves = 0;
	mean_b = lst_mean(stack_b);
	while (*stack_b)
	{
		if (*(int *)(*stack_b)->content == arr[*min])
		{
			moves = op("pa", stack_b, stack_a, moves);
			moves = op("ra", stack_a, NULL, moves);
			(*min)++;
		}
		else if (*(int *)(*stack_b)->content <= mean_b)
			moves = op("rb", stack_b, NULL, moves);
		else
			moves = op("pa", stack_b, stack_a, moves);
	}
	return (moves);
}

int	b_to_bot_a(t_list **stack_a, t_list **stack_b, int *arr, int *min)
{
	int	moves;

	moves = 0;
	while (*stack_b)
	{
		if (*(int *)(*stack_b)->content == arr[*min])
		{
			moves = op("pa", stack_b, stack_a, moves);
			moves = op("ra", stack_a, NULL, moves);
			(*min)++;
		}
		else
			moves = op("rb", stack_b, NULL, moves);
	}
	return (moves);
}

int	stack_sort(t_list **stack_a, t_list **stack_b, int *arr, int length)
{
	int		i;
	int		moves;
	int		min;
	int		mean_a;

	i = 0;
	moves = 0;
	min = 0;
	mean_a = lst_mean(stack_a);
	while (i < length)
	{
		if (*(int *)(*stack_a)->content <= mean_a)
			moves = op("pb", stack_a, stack_b, moves);
		else
			moves = op("ra", stack_a, NULL, moves);
		i++;
	}
	moves += b_to_top_bot_a(stack_a, stack_b, arr, &min);
	while (*(int *)(*stack_a)->content <= mean_a)
		moves = op("pb", stack_a, stack_b, moves);
	moves += b_to_bot_a(stack_a, stack_b, arr, &min);

