/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:01:25 by svieira           #+#    #+#             */
/*   Updated: 2021/11/10 16:04:22 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate_mandelbrot(double c_re, double c_im)
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

static int	color_mandelbrot(int n)
{
	// n = 0 => rgb(59, 66, 159)
	// n = MAX => rgb(94, 177, 191)
	return (get_trgb(0, 59 + 0.7 * n, 2.22 * n + 66, 0.64 * n + 159));
}

void	mandelbrot(t_mlx_vars *mlx_vars)
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
			n = iterate_mandelbrot(c_re, c_im);
			my_pixel_put(mlx_vars, x, y, color_mandelbrot(n));
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
	mandelbrot(&mlx_vars);
	mlx_put_image_to_window(mlx_vars.mlx, mlx_vars.window, mlx_vars.img, 0, 0);
	mlx_loop(mlx_vars.mlx);
	return (0);
}
