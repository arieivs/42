/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:02:02 by svieira           #+#    #+#             */
/*   Updated: 2021/11/22 20:39:04 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_vars *vars, int zoom_in, int x, int y)
{
	double	new_step;

	if (zoom_in)
		new_step = vars->step / 1.05;
	else
		new_step = vars->step * 1.05;
	vars->min_re = vars->min_re + (vars->step - new_step) * (double)x;
	vars->max_im = vars->max_im + (new_step - vars->step) * (double)y;
	vars->step = new_step;
	put_fractal_to_window(vars);
}

void	change_c(t_vars *vars, int x, int y)
{
	vars->c_re_julia = vars->min_re + vars->step * (double)x;
	vars->c_im_julia = vars->max_im - vars->step * (double)y;
	put_fractal_to_window(vars);
	printf("new c: %.3f %+.3f i\n", vars->c_re_julia, vars->c_im_julia);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4 || button == 5)
		zoom(vars, button == 4, x, y);
	if (button == 1 && vars->fractal == 'j')
		change_c(vars, x, y);
	return (0);
}

void	move(int keycode, t_vars *vars)
{
	if (keycode == LEFT)
		vars->min_re -= vars->step;
	else if (keycode == RIGHT)
		vars->min_re += vars->step;
	else if (keycode == DOWN)
		vars->max_im -= vars->step;
	else if (keycode == UP)
		vars->max_im += vars->step;
	put_fractal_to_window(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit(EXIT_SUCCESS);
	}
	if (keycode >= LEFT && keycode <= UP)
		move(keycode, vars);
	return (0);
}
