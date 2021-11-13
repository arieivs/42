/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:15:28 by svieira           #+#    #+#             */
/*   Updated: 2021/11/13 11:54:42 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# define WIDTH 1000 // 2000
# define HEIGHT 600 // 1200
# define MIN_RE -2.0
# define MAX_IM 1.2
# define STEP 0.004 // 0.002 // 2-(-2) / 2000
# define MAX_ITERATIONS 50

typedef struct	s_vars {
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	min_re;
	double	max_im;
	double	step;
	char	fractal;
	double	c_re_julia;
	double	c_im_julia;
}				t_vars;

/*
 * INTERFACE
 * checks and treats user input
 */
int		invalid_input(int ac, char **av);
void	print_instructions(void);
double	ft_atof(char *str);

/*
 * COLOR
 */
int		get_trgb(int t, int r, int g, int b);
int		color_fractal(int n);
void	my_pixel_put(t_vars *vars, int x, int y, int color);

/*
 * HOOKS
 */
int		mouse_hook(int button, int x, int y, t_vars *vars);
void	zoom(t_vars *vars, int zoom_in, int x, int y);

/*
 * MANDELBROT
 */
void	mandelbrot(t_vars *vars);

/*
 * JULIA
 */
void	julia(t_vars *vars);

/*
 * MAIN
 */
void	put_fractal_to_window(t_vars *vars);

#endif
