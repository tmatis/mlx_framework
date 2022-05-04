#ifndef GRAPHIC_H
# define GRAPHIC_H

#include "draw_util/draw_util.h"

# define KEY_ESC 65307



void graphic(void);

/* USER FUNCTIONS */
void frame_render(t_frame *frame);
void post_frame_render(t_mlx *mlx);
void key_press_event(int keycode);
void key_release_event(int keycode);
void mouse_click_event(int button, int x, int y);

#endif