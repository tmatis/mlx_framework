#include <stdlib.h>
#include <stdio.h>
#include "log.h"
#include "config.h"
#include "text_colors.h"
#include "../../minilibx/mlx.h"
#include "graphic.h"
#include <errno.h>
#include <string.h>
#include "mlx_hooks.h"

t_frame	frame_init(void *mlx, int x, int y)
{
	t_frame	frame;

	frame.img = mlx_new_image(mlx, x, y);
	if (!frame.img)
	{
		log_error(strerror(errno));
		exit(1);
	}
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel,
			&frame.line_length, &frame.endian);
	if (!frame.addr)
	{
		log_error(strerror(errno));
		exit(1);
	}
	frame.x = x;
	frame.y = y;
	return (frame);
}

void graphic(void)
{
	t_mlx	mlx_infos;
	mlx_infos.mlx = mlx_init();
	if (mlx_infos.mlx == NULL)
	{
		log_error("mlx initialization failed, exiting...");
		exit(EXIT_FAILURE);
	}
	mlx_infos.win = mlx_new_window(mlx_infos.mlx, WINDOW_X, WINDOW_Y, PROJECT_NAME);
	if (mlx_infos.win == NULL)
	{
		log_error("mlx window creation failed, exiting...");
		exit(EXIT_FAILURE);
	}
	mlx_infos.frame = frame_init(mlx_infos.mlx, WINDOW_X, WINDOW_Y);

	log_success("mlx initialization successfull [3/3]");

	mlx_hook(mlx_infos.win, 33, 0, close_hook, mlx_infos.mlx);
	mlx_hook(mlx_infos.win, 2, 1L, key_press_hook, mlx_infos.mlx);
	mlx_hook(mlx_infos.win, 3, 1L << 1, key_release_hook, NULL);
	mlx_mouse_hook(mlx_infos.win, mouse_hook, mlx_infos.mlx);
	mlx_loop_hook(mlx_infos.mlx, loop_hook, &mlx_infos);
	mlx_loop(mlx_infos.mlx);

	// free everything
	mlx_destroy_image(mlx_infos.mlx, mlx_infos.frame.img);
	mlx_destroy_window(mlx_infos.mlx, mlx_infos.win);
	mlx_destroy_display(mlx_infos.mlx);
	free(mlx_infos.mlx);

	log_success("mlx cleanup successfull [3/3]");
}