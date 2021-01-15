/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:02:38 by svieira           #+#    #+#             */
/*   Updated: 2021/01/15 00:11:01 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		grid[10][10] = {{0}};
/*int		grid[10][10] = {{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,1,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0}};*/

int		is_possible(int row, int col)
{
	int i;

	if (grid[row][col] != 0)
		return (0);
	i = 0;
	while (i < 10)
	{
		if (grid[i][col] != 0 || grid[row][i] != 0)
			return (0);
		// diagonal top-left to bottom-right, row - col = const
		if (i - row + col < 10 && grid[i][i - row + col] != 0)
			return (0);
		// diagonal from top-right to bottom-left, row + col = const
		if (row - i + col > 0 && grid[i][row - i + col] != 0)
			return (0);
		i++;
	}
	return (1);
}

int		is_valid(void)
{
	int row;
	int col;
	int queens_count;

	queens_count = 0;
	row = 0;
	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			if (grid[row][col] != 0)
				queens_count++;
			col++;
		}
		row++;
	}
	return (queens_count == 10);
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

void	solve(int *nb_queens, int *nb_sols)
{
	int row;
	int col;

	while (*nb_queens < 10)
	{
		col = 0;
		while (col < 10)
		{
			row = 0;
			while (row < 10)
			{
				if (is_possible(row, col))
				{
					grid[row][col] = 1;
					*nb_queens += 1;
					//printf("nb queens %d\n", *nb_queens);
					solve(nb_queens, nb_sols);
					//printf("hein\n");
					grid[row][col] = 0;
					*nb_queens -= 1;
				}
				row++;
			}
			col++;
		}
		return ;
	}
	*nb_sols += 1;
	display_solution();
}

int		ft_ten_queens_puzzle(void)
{
	int	nb_sols;
	int nb_queens;

	nb_sols = 0;
	nb_queens = 0;
	solve(&nb_queens, &nb_sols);
	return (nb_sols);
}
