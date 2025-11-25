#include "fract_ol.h"
#include <stdio.h>
#include <stdlib.h>

int is_number(char *str)
{
	int i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] <= '9' && str[i] >= '0') && !(str[i] == '.'))
			return (0);
		else
			i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	s_fract_julia	*fract_julia;
	if (argc == 1)
	{
		perror("Error: Missing argument!\nUsage:\n./fractol MANDELBROT\n./fractol JULIA <real> <imaginary> (Ex: ./fractol JULIA -0.8 0.156)");
		return (0);
	}
	
	if (ft_strnstr(argv[1], "MANDELBROT", 11))
	{
		fract_julia = NULL;
		fract_ol(fract_julia);
	}
	else if(argc >= 4 && ft_strnstr(argv[1], "JULIA", 6))
	{
		if (is_number(argv[2]) && is_number(argv[3]))
		{
			fract_julia = malloc(sizeof(s_fract_julia));
			fract_julia->julia_x = ft_atof(argv[2]);
			fract_julia->julia_y = ft_atof(argv[3]);
			fract_ol(fract_julia);
		}
		else
		{
			perror("Please input valid arg");
		}
	}
	else
	{
		perror("invalid argument");
		return (0);
	}
}