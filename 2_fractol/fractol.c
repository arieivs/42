/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:01:25 by svieira           #+#    #+#             */
/*   Updated: 2021/11/10 12:16:32 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_mlx_vars *mlx_vars, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx_vars->addr + y * mlx_vars->line_length
		+ x * (mlx_vars->bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

void	draw_mandelbrot(t_mlx_vars *mlx_vars)
{
	double min_re;
	double max_im;
	double step;
	double c_re;
	double c_im;
	double x;
	double y;

	min_re = (double)MINRE;
	max_im = (double)MAXIM;
	step = 0.002; // 1-(-2) / 1500
	y = 0;
	while (y < HEIGHT)
	{
		c_im = max_im + step * y;
		x = 0;
		while (x < WIDTH)
		{
			c_re = min_re + step * x;
			// check where in the mandelbrot is c
			// draw in (x,y) accordingly
			my_pixel_put(mlx_vars, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_mlx_vars	mlx_vars;

	mlx_vars.mlx = mlx_init();
	mlx_vars.window = mlx_new_window(mlx_vars.mlx, WIDTH, HEIGHT, "Janela");
	mlx_vars.img = mlx_new_image(mlx_vars.mlx, WIDTH, HEIGHT);
	mlx_vars.addr = mlx_get_data_addr(mlx_vars.img, &mlx_vars.bits_per_pixel,
			&mlx_vars.line_length, &mlx_vars.endian);
	// draw the fractal in the image
	draw_mandelbrot(&mlx_vars);
	mlx_put_image_to_window(mlx_vars.mlx, mlx_vars.window, mlx_vars.img, 0, 0);
	mlx_loop(mlx_vars.mlx);
	return (0);
}
