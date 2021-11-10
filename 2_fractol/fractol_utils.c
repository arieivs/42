/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:59:29 by svieira           #+#    #+#             */
/*   Updated: 2021/11/10 16:54:28 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_pixel_put(t_mlx_vars *mlx_vars, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx_vars->addr + y * mlx_vars->line_length
		+ x * (mlx_vars->bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

int	mouse_hook(int button, int x, int y, t_mlx_vars *mlx_vars)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom(mlx_vars, 1);
	else if (button == 5)
		zoom(mlx_vars, 0);
	return (0);
}
