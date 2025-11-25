/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free_management.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:16:44 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/17 12:58:13 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <stdlib.h>

void	ft_lstclear(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = lst-> next;
		free(lst);
		lst = tmp;
	}
}

void	free_split(char **trash)
{
	int	i;

	i = 0;
	while (trash && trash[i])
	{
		free(trash[i]);
		i++;
	}
	free(trash);
}
