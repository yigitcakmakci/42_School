/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:49:32 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/01 18:03:49 by ycakmakc         ###   ########.fr       */
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

int	*push_swap(int argc, char **argv)
{
	char	**tmp;
	int		*result;

	tmp = set_tmp(argc, argv);
	if (!tmp)
		return (NULL);
	if (argc == 1)
	{
		free_split(tmp);
		return (NULL);
	}
	if (!check_argv(tmp))
	{		
		write(1, "Error\n", 7);
		free_split(tmp);
		return (NULL);
	}
	result = sort_and_return(tmp);
	return (result);
}
