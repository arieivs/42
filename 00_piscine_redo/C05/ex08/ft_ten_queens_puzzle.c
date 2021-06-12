/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:02:38 by svieira           #+#    #+#             */
/*   Updated: 2021/01/15 18:53:12 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		grid[10][10] = {{0}};

int		is_possible(int row, int col)
{
	int i;
	int diag;

	if (grid[row][col] != 0)
		return (0);
	i = 0;
	while (i < 10)
	{
		if (grid[i][col] != 0 || grid[row][i] != 0)
			return (0);
		// diagonal top-left to bottom-right, row - col = const
		diag = i - row + col;
		if (diag >= 0 && diag < 10 && grid[i][diag] != 0)
			return (0);
		// diagonal from top-right to bottom-left, row + col = const
		diag = row - i + col;
		if (diag >= 0 && diag < 10 && grid[i][diag] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	display_solution(void)
{
	int		row;
	int		col;
	char	position;

	col = 0;
	while (col < 10)
	{
		row = 0;
		while (row < 10 && grid[row][col] == 0)
			row++;
		position = row + '0';
		write(1, &position, 1);
		col++;
	}
	write(1, "\n", 1);
}

void	solve(int col, int *nb_sols)
{
	int row;

	if (col == 10)
	{
		*nb_sols += 1;
		display_solution();
	}
	else
	{
		row = 0;
		while (row < 10)
		{
			if (is_possible(row, col))
			{
				grid[row][col] = 1;
				solve(col + 1, nb_sols);
				grid[row][col] = 0;
			}
			row++;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int	nb_sols;

	nb_sols = 0;
	solve(0, &nb_sols);
	return (nb_sols);
}
