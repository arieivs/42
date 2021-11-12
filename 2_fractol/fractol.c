/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:01:25 by svieira           #+#    #+#             */
/*   Updated: 2021/11/12 12:49:01 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_float(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return (0);
		i++;
	}
	return (1);
}

int	invalid_input(int ac, char **av)
{
	if (ac == 2 && (av[1][0] == 'm' || av[1][0] == 'j') && av[1][1] == 0)
		return (0);
	if (ac == 4 && av[1][0] == 'j' && av[1][1] == 0 && is_float(av[2]) &&
		is_float(av[3]))
		return (0);
	return (1);
}

void	print_instructions(void)
{
	printf("Please provide the following parameters:\n\
	m - for displaying the Mandelbrot set\n\
	j - for displaying a Julia set\n");
	printf("For Julia set you may choose the constant c ");
	printf("by providing Re(c) and Im(c)\n\
	choose numbers between -1.0 and 1.0\n\
	e.g: ./fractol j 0.285 0\n");
}

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
	/*if (vars->fractal == 'j')
	{
		vars->c_re_julia = ft_atof(av[2]);
		vars->c_im_julia = ft_atof(av[3]);
	}*/
}

void	put_fractal_to_window(t_vars *vars)
{
	if (vars->fractal == 'm')
		mandelbrot(vars);
	else if (vars->fractal == 'j')
		julia(vars);
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img, 0, 0);
}	

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
	put_fractal_to_window(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
