/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:59:29 by svieira           #+#    #+#             */
/*   Updated: 2021/12/10 14:22:13 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
 * COLOUR SCHEME
 * n = 0 => rgb(59, 66, 159)
 * n = MAX => rgb(94, 177, 191)
 */

int	color_fractal(int n)
{
	return (get_trgb(0, 59 + 0.7 * n, 2.22 * n + 66, 0.64 * n + 159));
}

void	my_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*pixel;

	pixel = vars->addr + y * vars->line_length
		+ x * (vars->bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}
