#include <stdio.h>
#include "log.h"
#include "config.h"
#include "text_colors.h"
#include "../../minilibx/mlx.h"
#include "graphic.h"

int	loop_hook(t_mlx *mlx)
{
	frame_render(&mlx->frame);
	mlx_put_image_to_window(
		mlx->mlx,
		mlx->win,
		mlx->frame.img,
		0,
		0);
	post_frame_render(mlx);
	return (0);
}

int key_press_hook(int keycode, void *mlx)
{
	if (SHOW_KEY_PRESSED)
		printf("Key pressed code: %d\n", keycode);
	if (keycode == KEY_ESC)
		mlx_loop_end(mlx);
	key_press_event(keycode);
	return (0);
}

int key_release_hook(int keycode)
{
	if (SHOW_KEY_PRESSED)
		printf("Key released code: %d\n", keycode);
	key_release_event(keycode);
	return (0);
}

int close_hook(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

int mouse_hook(int button, int x, int y)
{
	if (SHOW_KEY_PRESSED)
		printf("Mouse clicked: button: %d, x: %d, y: %d\n", button, x, y);
	mouse_click_event(button, x, y);
	return (0);
}