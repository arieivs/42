/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:01:25 by svieira           #+#    #+#             */
/*   Updated: 2021/11/09 16:44:01 by svieira          ###   ########.fr       */
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
	// from (0,0) to (WIDTH - 1, HEIGHT - 1)
}

int	main(void)
{
	t_mlx_vars	mlx_vars;

	mlx_vars.mlx = mlx_init();
	mlx_vars.window = mlx_new_window(mlx_vars.mlx, WIDTH, HEIGHT, "Janela");
	mlx_vars.img = mlx_new_img(mlx_vars.mlx, WIDTH, HEIGHT);
	mlx_vars.addr = mlx_get_data_addr(mlx_vars.img, &mlx_vars.bits_per_pixel,
			&mlx_vars.line_length, &mlx_vars.endian);
	// draw the fractal in the image
	mlx_put_image_to_window(mlx_vars.mlx, mlx_vars.window, mlx_vars.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
