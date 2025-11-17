/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard_coded.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:53:41 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/07 11:40:16 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <stdlib.h>

static void	sorting(int *x, t_stack **a)
{
	if (x[0] > x[1] && x[1] < x[2] && x[0] < x[2])
		sa(a);
	else if (x[0] > x[1] && x[1] > x[2])
	{
		sa(a);
		rra(a);
	}
	else if (x[0] > x[1] && x[1] < x[2] && x[0] > x[2])
		ra(a);
	else if (x[0] < x[1] && x[1] > x[2] && x[0] < x[2])
	{
		sa(a);
		ra(a);
	}
	else if (x[0] < x[1] && x[1] > x[2] && x[0] > x[2])
		rra(a);
}

void	sort_hard_coded(t_stack **a)
{
	int		*x;
	int		i;
	t_stack	*research_situation;

	x = malloc(sizeof(int) * stack_len(*a));
	i = 0;
	research_situation = *a;
	while (research_situation)
	{
		x[i] = research_situation-> value;
		research_situation = research_situation-> next;
		i++;
	}
	sorting(x, a);
	free(x);
}
