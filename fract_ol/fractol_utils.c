/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:36:25 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/25 18:35:25 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	free_all(t_fractol *fract)
{
	free(fract->julia);
	free(fract);
}

t_fractol	*get_mapping(t_fractol *fract, int x, int y)
{
	double	range_r;
	double	range_i;

	range_r = fract->fol.max_r - fract->fol.min_r;
	range_i = fract->fol.max_i - fract->fol.min_i;
	fract->fol.c_real = fract->fol.min_r + (x / (double)WIDTH * range_r);
	fract->fol.c_imag = fract->fol.min_i + (y / (double)HEIGHT * range_i);
	return (fract);
}

int	calculate_mandelbrot(t_fractol *fract, int x, int y)
{
	int		i;
	double	z_real;
	double	z_imag;
	double	z_real_temp;

	fract = get_mapping(fract, x, y);
	z_real = 0.0;
	z_imag = 0.0;
	i = 0;
	while ((z_real * z_real) + (z_imag * z_imag) <= 4.0 && i < MAX_ITERATION)
	{
		z_real_temp = z_real;
		z_real = z_real_temp * z_real_temp - z_imag * z_imag
			+ fract->fol.c_real;
		z_imag = 2.0 * z_real_temp * z_imag + fract->fol.c_imag;
		i++;
	}
	return (i);
}

int	calculate_julia(t_fractol *fract, int x, int y)
{
	int		i;
	double	z_real;
	double	z_imag;
	double	z_real_temp;

	fract->fol.c_real = fract->julia->julia_x;
	fract->fol.c_imag = fract->julia->julia_y;
	z_real = fract->fol.min_r + (x / (double)WIDTH) * (fract->fol.max_r
			- fract->fol.min_r);
	z_imag = fract->fol.min_i + (y / (double)HEIGHT) * (fract->fol.max_i
			- fract->fol.min_i);
	i = 0;
	while ((z_real * z_real) + (z_imag * z_imag) <= 4.0 && i < MAX_ITERATION)
	{
		z_real_temp = z_real * z_real - z_imag * z_imag + fract->fol.c_real;
		z_imag = 2.0 * z_real * z_imag + fract->fol.c_imag;
		z_real = z_real_temp;
		i++;
	}
	return (i);
}

void	print_pixel(t_fractol *fract, int x, int y, int color)
{
	char	*dst;

	dst = fract->addr + (y * fract->size_line + x * (fract->bitperpix / 8));
	*(unsigned int *)dst = color;
}
