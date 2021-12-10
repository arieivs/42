/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:01:25 by svieira           #+#    #+#             */
/*   Updated: 2021/11/22 20:02:14 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_vars(t_vars *vars, char **av)
{
	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Janela");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->min_re = MIN_RE;
	vars->max_im = MAX_IM;
	vars->step = STEP;
	vars->fractal = av[1][0];
	vars->c_re_julia = 0.0;
	vars->c_im_julia = 0.0;
	if (vars->fractal == 'j' && is_float(av[2]) && is_float(av[3]))
	{
		vars->c_re_julia = ft_atof(av[2]);
		vars->c_im_julia = ft_atof(av[3]);
	}
}

void	put_fractal_to_window(t_vars *vars)
{
	if (vars->fractal == 'm')
		mandelbrot(vars);
	else if (vars->fractal == 'j')
		julia(vars);
	else if (vars->fractal == 's')
		burnships(vars);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img, 0, 0);
}	

int	main(int ac, char **av)
{
	t_vars	vars;

	if (invalid_input(ac, av))
	{
		print_instructions();
		return (0);
	}
	init_vars(&vars, av);
	mlx_mouse_hook(vars.window, mouse_hook, &vars);
	mlx_key_hook(vars.window, key_hook, &vars);
	put_fractal_to_window(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
