/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:37:37 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/25 18:35:25 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

t_fol	init_fractal_data(void)
{
	t_fol	fol;

	fol.min_r = -2.0;
	fol.max_r = 2.0;
	fol.min_i = -2.0;
	fol.max_i = 2.0;
	return (fol);
}

t_fractol	*create_scene(void)
{
	t_fractol	*fract;

	fract = malloc(sizeof(t_fractol));
	if (!fract)
		return (NULL);
	fract->src_ptr = mlx_init();
	if (!fract->src_ptr)
		return (perror("mlx_init failed"), free(fract), NULL);
	fract->win_ptr = mlx_new_window(fract->src_ptr, WIDTH, HEIGHT, "fractol");
	if (!fract->win_ptr)
		return (perror("mlx_win failed"), free(fract->src_ptr), free(fract),
			NULL);
	fract->img_ptr = mlx_new_image(fract->src_ptr, WIDTH, HEIGHT);
	if (!fract->img_ptr)
	{
		mlx_destroy_window(fract->src_ptr, fract->win_ptr);
		return (perror("mlx_img failed"), NULL);
	}
	fract->addr = mlx_get_data_addr(fract->img_ptr, &fract->bitperpix,
			&fract->size_line, &fract->endian);
	fract->fol = init_fractal_data();
	return (fract);
}

int	calculate_color(int iteration)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == MAX_ITERATION)
		return (0xfffffff);
	t = (double)iteration;
	r = (int)(9.0 * (255.0 + cos(0.9 * t + 0)));
	g = (int)(9.0 * (42.0 + cos(0.9 * t + 2.094)));
	b = (int)(9.0 * (42.0 + cos(0.9 * t + 4.188)));
	return (r << 16 | g << 8 | b);
}

void	render_fractal(t_fractol *fract)
{
	int	iteration;
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fract->julia != NULL)
				iteration = calculate_julia(fract, x, y);
			else
				iteration = calculate_mandelbrot(fract, x, y);
			color = calculate_color(iteration);
			print_pixel(fract, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->src_ptr, fract->win_ptr, fract->img_ptr, 0,
		0);
}

void	fractol(t_fract_julia *fract_julia)
{
	t_fractol	*fract;

	fract = create_scene();
	if (fract == NULL)
		return ;
	fract->julia = fract_julia;
	render_fractal(fract);
	mlx_key_hook(fract->win_ptr, key_handler, fract);
	mlx_mouse_hook(fract->win_ptr, mouse_handler, fract);
	mlx_loop(fract->src_ptr);
}
