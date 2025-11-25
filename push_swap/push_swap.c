/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:49:32 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/23 19:15:49 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <unistd.h>
#include <stdlib.h>

static int	*sort_and_return(char **tmp)
{
	t_stack	*a;
	t_stack	*b;
	int		*result;

	a = NULL;
	b = NULL;
	a = stack_init(tmp);
	free_split(tmp);
	choose_stralegy(&a, &b);
	result = array_init(a);
	if (!result)
		return (NULL);
	ft_lstclear(a);
	ft_lstclear(b);
	return (result);
}

int	have_empty_arg(int argc, char **argv)
{
	int	digit_ctrl;
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		digit_ctrl = 0;
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] <= '9' && argv[i][j] >= '0')
				digit_ctrl = 1;
			j++;
		}
		if (digit_ctrl == 0)
			return (1);
		i++;
	}
	return (0);
}

int	*push_swap(int argc, char **argv)
{
	char	**tmp;
	int		*result;

	if (argc == 1)
		return (0);
	if (have_empty_arg(argc, argv))
	{
		write(1, "Error\n", 7);
		return (NULL);
	}
	tmp = set_tmp(argc, argv);
	if (!check_argv(tmp))
	{
		write(1, "Error\n", 7);
		free_split(tmp);
		return (NULL);
	}
	result = sort_and_return(tmp);
	return (result);
}
