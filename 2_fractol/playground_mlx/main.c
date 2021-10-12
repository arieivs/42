#include <mlx.h>

typedef struct s_img_info {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_info;

void	my_pixel_put(t_img_info *img, int x, int y, int color)
{
	char	*pixel;
	
	pixel = img->addr + y * img->line_length + x * (img->bits_per_pixel / 8);
	*(unsigned int *)pixel = color;
}

int	main()
{
	void		*mlx;
	void		*mlx_window;
	t_img_info	img;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 600, 300, "Janela");
	img.img = mlx_new_image(mlx, 600, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
