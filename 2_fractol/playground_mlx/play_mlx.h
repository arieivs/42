#ifndef PLAY_MLX_H
# define PLAY_MLX_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

typedef struct s_img_info {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_info;

int		get_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		add_shade(int trgb, float shade);
int		get_opposite(int trgb);
void	my_pixel_put(t_img_info *img, int x, int y, int color);
void	draw_line(t_img_info *img, int xi, int yi, int xf, int yf, int color);
void	draw_square(t_img_info *img, int xi, int yi, int size, int color);
void	draw_circle(t_img_info *img, int x0, int y0, int r, int color);

#endif
