#include "play_mlx.h"

int	key_hook(int keycode, t_mlx_vars *mlx_vars)
{
	(void)mlx_vars;

	printf("Hello from key %d!\n", keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_mlx_vars *mlx_vars)
{
	(void)button;
	(void)mlx_vars;

	printf("Hello from mouse, coordinates x: %d, y: %d\n", x, y);
	return (0);
}
