/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:54:09 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 17:50:07 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	do_rev_rotate_both(t_stack **a, t_stack **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b, true);
	}
}

static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b, true);
	}
}

static void	do_rotate(t_stack **s, int *cost, char c)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			if (c == 'a')
				ra(s, true);
			if (c == 'b')
				rb(s, true);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (c == 'a')
				rra(s, true);
			if (c == 'b')
				rrb(s, true);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate(a, &cost_a, 'a');
	do_rotate(b, &cost_b, 'b');
	pa(a, b, true);
}
