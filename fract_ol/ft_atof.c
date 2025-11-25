/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:59:06 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/25 18:10:39 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atof(char *str)
{
	double	result;
	double	fraction_mult;
	int		sign;
	int		i;

	result = 0.0;
	fraction_mult = 1.0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.' || str[i] == ',')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			fraction_mult /= 10.0;
			result = result + (double)(str[i] - '0') *fraction_mult;
			i++;
		}
	}
	return (result * sign);
}
