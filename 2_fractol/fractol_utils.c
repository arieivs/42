/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:59:29 by svieira           #+#    #+#             */
/*   Updated: 2021/11/12 01:11:10 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*pixel;

	pixel = vars->addr + y * vars->line_length
		+ x * (vars->bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4 || button == 5)
		zoom(vars, button == 4, x, y);
	return (0);
}
