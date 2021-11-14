/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnships.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:24:54 by svieira           #+#    #+#             */
/*   Updated: 2021/11/14 01:03:09 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate_burnships(double c_re, double c_im)
{
	int		n;
	double	z_re;
	double	z_re_tmp;
	double	z_im;
	double	mod;

	n = 0;
	z_re = 0;
	z_im = 0;
	while (++n < MAX_ITERATIONS)
	{
		z_re_tmp = z_re * z_re - (z_im * z_im) + c_re;
		mod = z_re * z_im;
		if (mod < 0)
			mod *= -1;
		z_im = 2 * mod + c_im;
		z_re = z_re_tmp;
		if ((z_re * z_re + z_im * z_im) > 4)
			return (n);
	}
	return (n);
}

void	burnships(t_vars *vars)
{
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	int		n;

	y = 0;
	while (y < HEIGHT)
	{
		c_im = - vars->max_im + vars->step * y;
		x = 0;
		while (x < WIDTH)
		{
			c_re = vars->min_re + vars->step * x;
			n = iterate_burnships(c_re, c_im);
			my_pixel_put(vars, x, y, color_fractal(n));
			x++;
		}
		y++;
	}
}
