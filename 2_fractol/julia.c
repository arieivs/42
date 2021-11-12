/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:36:33 by svieira           #+#    #+#             */
/*   Updated: 2021/11/12 13:19:40 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate_julia(double z_re, double z_im)
{
	int		n;
	double	c_re;
	double	c_im;
	double	z_re_tmp;

	n = 0;
	c_re = -0.835; // think where to get it from
	c_im = -0.232; // same same
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

void	julia(t_vars *vars)
{
	double	z_re;
	double	z_im;
	double	x;
	double	y;
	int		n;

	y = 0;
	while (y < HEIGHT)
	{
		z_im = vars->max_im - vars->step * y;
		x = 0;
		while (x < WIDTH)
		{
			z_re = vars->min_re + vars->step * x;
			n = iterate_julia(z_re, z_im);
			my_pixel_put(vars, x, y, color_fractal(n));
			x++;
		}
		y++;
	}
}
