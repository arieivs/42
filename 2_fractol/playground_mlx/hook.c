#include "play_mlx.h"

int	key_hook(int keycode, t_mlx_vars *mlx_vars)
{
	(void)mlx_vars;

	if (keycode == 53) // esc
		mlx_destroy_window(mlx_vars->mlx, mlx_vars->window);
	printf("Hello from key %d!\n", keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_mlx_vars *mlx_vars)
{
	(void)mlx_vars;

	printf("Hello from mouse, button: %d,  x: %d, y: %d\n", button, x, y);
	return (0);
}

int	greet(t_mlx_vars *mlx_vars)
{
	(void)mlx_vars;

	printf("Welcome! :D\n");
	return (0);
}

int	goodbye(t_mlx_vars *mlx_vars)
{
	(void)mlx_vars;

	printf("Goodbye...\n");
	return (0);
}
