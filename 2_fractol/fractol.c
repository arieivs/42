/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:01:25 by svieira           #+#    #+#             */
/*   Updated: 2021/11/10 17:26:58 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Janela");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->min_re = MIN_RE;
	vars->max_im = MAX_IM;
	vars->step = STEP;
}

void	put_fractal_to_window(t_vars *vars)
{
	if (vars->fractal == 'M')
		mandelbrot(vars);
	// else if 'J' julia set
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img, 0, 0);
}	

void	zoom(t_vars *vars, int zoom_in)
{
	if (zoom_in)
		vars->step /= 2;
	else
		vars->step *= 2;
	put_fractal_to_window(vars);
}

int	main(void)
{
	t_vars	vars;

	init_vars(&vars);
	// take the fractal we want from input
	vars.fractal = 'M';
	mlx_mouse_hook(vars.window, mouse_hook, &vars);
	put_fractal_to_window(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
