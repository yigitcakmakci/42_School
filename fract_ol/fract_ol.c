#include "fract_ol.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

s_fract_ol	*create_scene(void)
{
	s_fract_ol	*fract;

	fract = malloc(sizeof(s_fract_ol));
	fract->src_ptr = mlx_init();
	if (fract->src_ptr == 0)
	{
		perror("mlx_init crack!");
		return (NULL);
	}

	fract->win_ptr = mlx_new_window(fract->src_ptr, WIDTH, HEIGHT, "MANDELBROT");
	if (fract->win_ptr == 0)
	{
		perror("mlx_new_window crack!");
		return (NULL);
	}
	fract->fol.min_r = -2.0;
	fract->fol.max_r = 2.0;
	fract->fol.min_i = -2.0;
	fract->fol.max_i = 2.0;
	fract->img_ptr = mlx_new_image(fract->src_ptr, WIDTH, HEIGHT);
	if (fract->img_ptr == 0)
	{
		perror("mlx_new_image crack!");
		return (NULL);
	}
	fract->addr = mlx_get_data_addr(fract->img_ptr, &fract->bitperpix,
			&fract->size_line, &fract->endian);
	if (fract->addr == NULL)
	{
		return (NULL);
	}
	return (fract);
}

int	calculate_color(int iteration)
{
	if (iteration == MAX_ITERATION)
        return (0xfffffff); 

    double t = (double)iteration; 
    int R = (int)(9.0 * (255.0 + cos(0.9 * t + 0)));
    int G = (int)(9.0 * (42.0 + cos(0.9 * t + 2.094)));
    int B = (int)(9.0 * (42.0 + cos(0.9 * t + 4.188)));

    return (R << 16 | G << 8 | B);	
}

void render_fractal(s_fract_ol *fract)
{
	int iteration;
	int	x;
	int	y;
	int color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iteration = calculate_mandelbrot(fract, x, y);
			color = calculate_color(iteration);
			print_pixel(fract, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract-> src_ptr, fract-> win_ptr, fract ->img_ptr, 0, 0);
}

void	fract_ol(s_fract_julia fract_julia)
{
	s_fract_ol *fract;
	if ((fract = create_scene()) == NULL)
		return ;
	render_fractal(fract);
	mlx_key_hook(fract-> win_ptr, key_handler, fract);
	mlx_mouse_hook(fract-> win_ptr, mouse_handler, fract);
	mlx_loop(fract->src_ptr);
}