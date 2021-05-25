/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:40:32 by svieira           #+#    #+#             */
/*   Updated: 2021/05/25 13:13:21 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* BUBBLE SORT
keep on raing
when one is bigger than the next, sa, then ra
need to know how big the stack is
keep doing it until it's sorted
alternative: pb instead of ra
*/

/* SELECTION SORT
go though the list and find the smallest
pb all of it including the smallest
rb
pa everything back except for the smallest
do it all again until it's sorted
*/

/*Both strategies seem largely inefficient...*/

/* QUICK SORT
 * Iterate over the stack A (ra's)
 * if elememt is smaller than average, push to b (pb)
 * right now we have: upper half in A, lower half in B
 * Iterate over the stack B (rb's)
 * if element is bigger than average in B, push to A (pa)
 * if element is the minimum in the whole B stack, push to bottom of A (pa + ra)
 * to think: how do I keep track of the minimum? I could of course, order an array with the same content of the stack to compare... but... I mean...
