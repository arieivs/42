/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:15:28 by svieira           #+#    #+#             */
/*   Updated: 2021/11/23 12:15:47 by svieira          ###   ########.fr       */
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
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

typedef struct s_vars {
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
int		is_float(char *str);
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
void	zoom(t_vars *vars, int zoom_in, int x, int y);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

/*
 * MANDELBROT
 */
void	mandelbrot(t_vars *vars);

/*
 * JULIA
 */
void	julia(t_vars *vars);

/*
 * BURNSHIPS
 */
void	burnships(t_vars *vars);

/*
 * MAIN
 */
void	put_fractal_to_window(t_vars *vars);

#endif
