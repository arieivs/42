/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:22:55 by svieira           #+#    #+#             */
/*   Updated: 2021/06/02 12:27:01 by svieira          ###   ########.fr       */
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

int	stack_sort(t_list *stack_a, t_list *stack_b, int *arr)
{

