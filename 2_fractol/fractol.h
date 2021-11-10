/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:15:28 by svieira           #+#    #+#             */
/*   Updated: 2021/11/10 16:52:52 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# define WIDTH 1500
# define HEIGHT 1200
# define MIN_RE -2.0
# define MAX_IM 1.2
# define STEP 0.002 // 1-(-2) / 1500
# define MAX_ITERATIONS 50

typedef struct	s_mlx_vars {
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
}				t_mlx_vars;

int		get_trgb(int t, int r, int g, int b);
void	my_pixel_put(t_mlx_vars *mlx_vars, int x, int y, int color);
int		mouse_hook(int button, int x, int y, t_mlx_vars *mlx_vars);
void	zoom(t_mlx_vars *mlx_vars, int zoom_in);

#endif
