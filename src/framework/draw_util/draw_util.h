#ifndef DRAW_UTIL_H
# define DRAW_UTIL_H

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
} t_frame;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_frame	frame;
} t_mlx;

int	rgb_to_color(int r, int g, int b);
void frame_put_pixel(t_frame *f, int x, int y, int color);
void draw_rectangle(t_frame *f, int x, int y, int w, int h, int color);
void draw_line(t_frame *f, int x0, int y0, int x1, int y1, int color);
void put_string(t_mlx *mlx,  int x, int y, int color, char *string);

#endif