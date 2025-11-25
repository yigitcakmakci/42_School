#include "fract_ol.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		perror("Wrong Arg!");
		return (0);
	}
	
	if (ft_strnstr(argv[1], "MANDELBROT", 11))
	{
		fract_ol();
	}
	else if(ft_strnstr(argv[1], "JULIA", 6))
	{
		s_fract_julia fract_julia;
		fract_julia = malloc(sizeof(s_fract_julia));
		fract_julia.julia_x = ft_atoi(argv[2]);
		fract_julia.julia_y = ft_atoi(argv[3]);
		fract_ol(fract_julia);
	}
	else
	{
		perror("Wrong Arg!");
		return (0);
	}
}