/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:00:27 by svieira           #+#    #+#             */
/*   Updated: 2021/06/02 12:22:17 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	quick_sort(int	*arr, int start, int end)
{
	int	i;
	int	fut_pivot_i;
	int	pivot;
	int	tmp;

	i = start;
	fut_pivot_i = start;
	pivot = arr[end];
	while (i < end - 1)
	{
		if (arr[i] < pivot)
		{
			tmp = arr[i];
			arr[i] = arr[fut_pivot_i];
			arr[fut_pivot_i] = tmp;
			fut_pivot_i++;
		}
		i++;
	}
	arr[end] = arr[fut_pivot_i];
	arr[fut_pivot_i] = pivot;
	quick_sort(arr, start, fut_pivot_i - 1);
	quick_sort(arr, fut_pivot_i + 1, end);
}
