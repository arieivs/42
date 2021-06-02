/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:22:55 by svieira           #+#    #+#             */
/*   Updated: 2021/06/02 23:02:59 by svieira          ###   ########.fr       */
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

int	arr_mean(int *arr, int length)
{
	int i;
	int	mean;

	i = 0
	while (i < length)
		mean += arr[i++];
	mean /= length;
	return (mean);
}

int	stack_sort(t_list *stack_a, t_list *stack_b, int *arr, int length)
{
	t_list	*curr_a;
	int		instructions;
	int		mean;

	curr_a = stack_a;
	instructions = 0;
	mean = arr_mean(arr, length);
	while (curr_a)
	{
		if (*(int *)curr_a->content <= mean)
		{
			push(stack_a, stack_b);
			instructions = display_op("pb", instructions);
		}
		else
		{
			rotate(stack_a);
			instructions = display_op("ra", instructions);
		}
		curr_a = curr_a->next;
	}


