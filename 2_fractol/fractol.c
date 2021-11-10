/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:01:25 by svieira           #+#    #+#             */
/*   Updated: 2021/11/10 15:02:25 by svieira          ###   ########.fr       */
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

int		iterate_mandelbrot(double c_re, double c_im)
{
	int		n;
	double	z_re;
	double	z_re_tmp;
	double	z_im;

	n = 0;
	z_re = 0;
	z_im = 0;
	while (++n < MAX_ITERATIONS)
	{
		z_re_tmp = z_re * z_re - (z_im * z_im) + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re_tmp;
		if ((z_re * z_re + z_im * z_im) > 4)
			return (n);
	}
	return (n);
}

void	draw_mandelbrot(t_mlx_vars *mlx_vars)
{
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	int		n;

	y = 0;
	while (y < HEIGHT)
	{
		c_im = MAX_IM - STEP * y;
		x = 0;
		while (x < WIDTH)
		{
			c_re = MIN_RE + STEP * x;
			// check where in the mandelbrot is c
			// draw in (x,y) accordingly
			n = iterate_mandelbrot(c_re, c_im);
			if (n == MAX_ITERATIONS)
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
