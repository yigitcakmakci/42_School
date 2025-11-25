/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:03:10 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/23 19:13:36 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	push_smallest(t_stack **a, t_stack **b)
{	
	int	counter_target;
	int	counter;

	counter_target = stack_len(*a) - 3;
	counter = 0;
	while (counter < counter_target)
	{
		if ((*a)->index == counter)
		{
			pb(a, b);
			counter++;
		}
		if (counter != counter_target && (*a)->index != counter)
			ra(a);
	}
}

void	sort_selection(t_stack **a, t_stack **b)
{
	push_smallest(a, b);
	sort_hard_coded(a);
	if (((*b)-> next != ((void *)0)) && ((*b)-> value < (*b)-> next -> value))
		sb(b);
	while (*b)
		pa(a, b);
}
