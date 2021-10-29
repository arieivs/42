#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "play_mlx.h"

void	test_colours(void)
{
	int	t = 0;
	int	r = 115;
	int g = 186;
	int b = 155;
	int	trgb;
	int	shaded;
	int	black;
	int	opposite;

	trgb = get_trgb(t, r, g, b);
	printf("Int: %d\n", trgb);
	printf("TRGB: 0X%02X%X%X%X\n", get_t(trgb), get_r(trgb), get_g(trgb), get_b(trgb));
	shaded = add_shade(trgb, 0.5);
	black = add_shade(trgb, 1);
	printf("Shaded: 0X%02X%X%X%X | Black: 0X%02X%02X%02X%02X\n", get_t(shaded), get_r(shaded), get_g(shaded), get_b(shaded), get_t(black), get_r(black), get_g(black), get_b(black));
	opposite = get_opposite(trgb);
	printf("Opposite: 0X%02X%X%X%X\n", get_t(opposite), get_r(opposite), get_g(opposite), get_b(opposite));
}

int	main(void)
{
	void		*mlx;
	void		*mlx_window;
	t_img_info	img;

	//test_colours();
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 600, 300, "Janela");
	img.img = mlx_new_image(mlx, 600, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	draw_line(&img, 5, 5, 5, 5, 0x00FFFFFF); // white dot
	draw_line(&img, 6, 120, 6, 6, 0x0002C0A0); // EYEN green line
	draw_line(&img, 20, 120, 120, 20, 0x00FBF3E4); // EYEN bege line
	draw_square(&img, 100, 50, 100, 0x000000BB); // EYEN blue square
	draw_circle(&img, 500, 100, 50, 0x00FF9900); // EYEN orange circle
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
