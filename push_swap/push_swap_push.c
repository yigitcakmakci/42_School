/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:01:19 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/17 12:58:14 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <unistd.h>

static void	push_swap_push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (from == NULL || *from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = NULL;
	if (*to == NULL)
	{
		*to = tmp;
	}
	else
	{
		tmp->next = *to;
		*to = tmp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push_swap_push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push_swap_push(a, b);
	write(1, "pb\n", 3);
}
