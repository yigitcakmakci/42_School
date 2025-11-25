/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:18:35 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/25 17:57:34 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fract_ol.h"
#include <stdlib.h>

#define KEY_ESC 65307
#define MOUSE_SCROLL_UP 4
#define MOUSE_SCROLL_DOWN 5

int	close_handler(t_fract_ol *fract)
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

int	key_handler(int keycode, t_fract_ol *fract)
{
	if (keycode == KEY_ESC)
	{
		close_handler(fract);
	}
	return (0);
}

t_zoom	assign_t_zoom(int x, int y, double zoom_rate, t_fract_ol *fract)
{
	t_zoom	z;

	z.ratio_x = (double)x / WIDTH;
	z.ratio_y = (double)y / HEIGHT;
	z.range_r_old = (fract->fol.max_r) - (fract->fol.min_r);
	z.range_i_old = (fract->fol.max_i) - (fract->fol.min_i);
	z.range_r_new = z.range_r_old * zoom_rate;
	z.range_i_new = z.range_i_old * zoom_rate;
	z.shift_r = z.ratio_x * (z.range_r_old - z.range_r_new);
	z.shift_i = z.ratio_y * (z.range_i_old - z.range_i_new);
	return (z);
}

int	mouse_handler(int keycode, int x, int y, t_fract_ol *fract)
{
	double	zoom_rate;
	t_zoom	z;

	if (keycode == MOUSE_SCROLL_UP || keycode == MOUSE_SCROLL_DOWN)
	{
		if (keycode == MOUSE_SCROLL_UP)
			zoom_rate = 0.95;
		else
			zoom_rate = 1.05;
	}
	else
		return (0);
	z = assign_t_zoom(x, y, zoom_rate, fract);
	fract->fol.min_r += z.shift_r;
	fract->fol.max_r = fract->fol.min_r + z.range_r_new;
	fract->fol.min_i += z.shift_i;
	fract->fol.max_i = fract->fol.min_i + z.range_i_new;
	render_fractal(fract);
	return (0);
}
