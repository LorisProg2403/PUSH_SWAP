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

/* do_rotate_both:
*	Rotates both stack A and B until one of them is in position.
*	The given cost is positive since both positions are in the top half
*	of their respective stacks. The cost is decreased as the stacks are
*	rotated, when one reaches 0, the stack has been rotated as far as possible
*	and the top position is correct.
*/
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b, true);
	}
}

/* do_rotate:
*	Rotates stack until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be
*	rotated.
*/
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

/* do_move:
*	Chooses which move to make to get the B stack element to the correct
*	position in stack A.
*	If the costs of moving stack A and B into position match (i.e. both negative
*	of both positive), both will be	rotated or reverse rotated at the same time.
*	They might also be rotated separately, before finally pushing the top B element
*	to the top stack A.
*/
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
