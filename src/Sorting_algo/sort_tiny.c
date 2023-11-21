/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:49:50 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 17:50:23 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* find_highest_index:
*	Returns the highest index in a stack.
*/
static int	find_highest_index(t_stack *s)
{
	int	index;

	index = s->index;
	while (s)
	{
		if (s->index > index)
			index = s->index;
		s = s->next;
	}
	return (index);
}

/* tiny_sort:
*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
*	rather than value. Example:
*		values:		 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solution, 2 moves:
*	rra:
*		values:		 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		values:		 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/
void	tiny_sort(t_stack **s)
{
	int	highest;

	if (is_sorted(*s))
		return ;
	highest = find_highest_index(*s);
	if ((*s)->index == highest)
		ra(s, true);
	else if ((*s)->next->index == highest)
		rra(s, true);
	if ((*s)->index > (*s)->next->index)
		sa(s, true);
}
