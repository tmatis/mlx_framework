#ifndef MLX_HOOKS_H
# define MLX_HOOKS_H

#include "graphic.h"

int	loop_hook(t_mlx *mlx);
int key_press_hook(int keycode, void *mlx);
int key_release_hook(int keycode);
int close_hook(void *mlx);
int mouse_hook(int button, int x, int y);

#endif