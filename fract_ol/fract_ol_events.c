#include "minilibx-linux/mlx.h"
#include "fract_ol.h"
#include <stdlib.h>

#define KEY_ESC 65307
#define MOUSE_SCROLL_UP 4
#define MOUSE_SCROLL_DOWN 5

int	close_handler(s_fract_ol *fract)
{
	if (fract->img_ptr)
		mlx_destroy_image(fract->src_ptr, fract-> img_ptr);
	if (fract->win_ptr)
		mlx_destroy_window(fract->src_ptr, fract-> win_ptr);
	if (fract->src_ptr)
	{
		mlx_destroy_display(fract->src_ptr);
		free(fract->src_ptr);
	}
	if (fract->julia)
		free(fract->julia);
	free(fract);
	exit(0);
}

int	key_handler(int keycode, s_fract_ol *fract)
{
	if (keycode == KEY_ESC)
	{
		close_handler(fract);
	}
	return (0);
}

int	mouse_handler(int keycode, int x, int y, s_fract_ol *fract)
{
	double zoom_rate = 0.0;

	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
	{
		if (keycode == MOUSE_SCROLL_UP)
			zoom_rate = 0.95;
		else
			zoom_rate = 1.05;
	}

	else
	{
		return (0);
	}
	double ratio_x = (double)x / WIDTH;
	double ratio_y = (double)y / HEIGHT;

	double range_r_old = (fract->fol.max_r) - (fract->fol.min_r);
	double range_i_old = (fract->fol.max_i) - (fract->fol.min_i);

	double range_r_new = range_r_old * zoom_rate;
	double range_i_new = range_i_old * zoom_rate;

	double shift_r = ratio_x * (range_r_old - range_r_new);
	double shift_i = ratio_y * (range_i_old - range_i_new);

	fract->fol.min_r += shift_r;
	fract->fol.max_r = fract->fol.min_r + range_r_new;

	fract->fol.min_i += shift_i;
	fract->fol.max_i = fract->fol.min_i + range_i_new;

	render_fractal(fract);
	return (0);
}