#include "fract_ol.h"
#include <stdlib.h>

void	free_all(s_fract_ol *fract)
{
	free(fract->julia);
	free(fract);
}

s_fract_ol	*get_mapping(s_fract_ol *fract ,int x, int y)
{
	double range_r = fract->fol.max_r - fract->fol.min_r;
	double range_i = fract->fol.max_i - fract->fol.min_i;
	fract->fol.c_real = fract->fol.min_r + (x / (double)WIDTH * range_r);
	fract->fol.c_imag = fract->fol.min_i + (y / (double)HEIGHT * range_i);
	return (fract);
}

int	calculate_mandelbrot(s_fract_ol *fract ,int x, int y)
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
		z_real = z_real_temp * z_real_temp - z_imag * z_imag + fract->fol.c_real;
		z_imag = 2.0 * z_real_temp * z_imag + fract->fol.c_imag;
		i++;
	}
	return (i);
}

int	calculate_julia(s_fract_ol *fract, int x, int y)
{
	int		i;
	double	z_real;
	double	z_imag;
	double	z_real_temp;

	fract->fol.c_real = fract->julia->julia_x;
	fract->fol.c_imag = fract->julia->julia_y;

	z_real = fract->fol.min_r + (x / (double)WIDTH) * (fract->fol.max_r - fract->fol.min_r);
	z_imag = fract->fol.min_i + (y / (double)HEIGHT) * (fract->fol.max_i - fract->fol.min_i);
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

void	print_pixel(s_fract_ol *fract, int x, int y, int color)
{
	char *dst;
	dst = fract -> addr + (y* fract->size_line + x * (fract->bitperpix / 8));
	*(unsigned int*)dst = color;
}
