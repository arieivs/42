/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:59:29 by svieira           #+#    #+#             */
/*   Updated: 2021/11/10 17:24:43 by svieira          ###   ########.fr       */
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
	(void)x;
	(void)y;
	if (button == 4)
		zoom(vars, 1);
	else if (button == 5)
		zoom(vars, 0);
	return (0);
}
