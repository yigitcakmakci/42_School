/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:04:13 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/25 18:35:25 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <unistd.h>

void	print_error_and_exit(void)
{
	char	*msg;

	msg = "Error: Invalid arguments.\n"
		"Usage:\n"
		"  ./fractol MANDELBROT\n"
		"  ./fractol JULIA <real> <imaginary>\n"
		"  Example: ./fractol JULIA -0.8 0.156\n";
	write(2, msg, 115);
	exit(1);
}

int	is_valid_number(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
			dot_count++;
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		if (dot_count > 1)
			return (0);
		i++;
	}
	return (1);
}

void	handle_args(int argc, char **argv)
{
	t_fract_julia	*fract_julia;

	if (argc == 2 && !ft_strncmp(argv[1], "MANDELBROT", 11))
	{
		fractol(NULL);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "JULIA", 6))
	{
		if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
			print_error_and_exit();
		fract_julia = malloc(sizeof(t_fract_julia));
		if (!fract_julia)
			print_error_and_exit();
		fract_julia->julia_x = ft_atof(argv[2]);
		fract_julia->julia_y = ft_atof(argv[3]);
		fractol(fract_julia);
	}
	else
	{
		print_error_and_exit();
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		print_error_and_exit();
	handle_args(argc, argv);
	return (0);
}
