/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sorting_stralegy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:39:13 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/23 18:40:49 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	is_order(t_stack *a)
{
	while (a -> next != ((void *)0))
	{
		if (a -> index != ((a-> next -> index) - 1))
			return (0);
		a = a-> next;
	}
	return (1);
}

void	choose_stralegy(t_stack **a, t_stack **b)
{
	int	len;

	if (is_order(*a))
		return ;
	len = stack_len(*a);
	if (len < 2)
		return ;
	else if (len == 2)
	{
		if ((*a)-> value > (*a)->next-> value)
			sa(a);
	}
	else if (len == 3)
		sort_hard_coded(a);
	else if (len <= 5)
		sort_selection(a, b);
	else
		sort_chunk_based(a, b);
}
