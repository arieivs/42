/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:27:33 by svieira           #+#    #+#             */
/*   Updated: 2021/01/13 19:15:58 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tail_fib(int index, int curr, int next)
{
	if (index == 0)
		return (curr);
	if (index == 1)
		return (next);
	return (ft_tail_fib(index - 1, next, curr + next));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (ft_tail_fib(index, 0, 1));
}
