/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:02:02 by svieira           #+#    #+#             */
/*   Updated: 2021/11/13 12:00:20 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_vars *vars, int zoom_in, int x, int y)
{
	double	new_step;

	if (zoom_in)
		new_step = vars->step / 2;
	else
		new_step = vars->step * 2;
	vars->min_re = vars->min_re + (vars->step - new_step) * (double)x;
	vars->max_im = vars->max_im + (new_step - vars->step) * (double)y;
	vars->step = new_step;
	put_fractal_to_window(vars);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4 || button == 5)
		zoom(vars, button == 4, x, y);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53) // esc
		mlx_destroy_window(vars->mlx, vars->window);
	return (0);
}
