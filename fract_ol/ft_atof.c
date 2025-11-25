/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:59:06 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/25 18:22:57 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	get_decimal_part(char *str)
{
	double	fraction;
	double	mult;
	int		i;

	fraction = 0.0;
	mult = 1.0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		mult /= 10.0;
		fraction += (double)(str[i] - '0') *mult;
		i++;
	}
	return (fraction);
}

double	ft_atof(char *str)
{
	double	result;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.' || str[i] == ',')
		result += get_decimal_part(&str[i + 1]);
	return (result * sign);
}
