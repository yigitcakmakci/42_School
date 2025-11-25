/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:44:21 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/23 18:34:48 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	is_digit(char **tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[i])
	{
		j = 0;
		if (tmp[i][0] == '+' || tmp[i][0] == '-')
			j++;
		while (tmp[i][j])
		{
			if (!((tmp[i][j] >= '0' && tmp[i][j] <= '9')))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_number(char **tmp)
{
	int		i;
	long	number;

	i = 0;
	while (tmp[i])
	{
		number = ft_atoi_long(tmp[i]);
		if (!(number < 2147483648 && number > -2147483649))
			return (0);
		i++;
	}
	return (1);
}

int	is_same_value(char **tmp)
{
	int	i;
	int	j;
	int	same_count;

	i = 0;
	while (tmp[i])
	{
		same_count = 0;
		j = 0;
		while (tmp[j])
		{
			if (ft_atoi(tmp[i]) == ft_atoi(tmp[j]))
				same_count++;
			if (same_count == 2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_argv(char **tmp)
{
	if (!is_digit(tmp))
		return (0);
	if (!is_valid_number(tmp))
		return (0);
	if (!is_same_value(tmp))
		return (0);
	return (1);
}
