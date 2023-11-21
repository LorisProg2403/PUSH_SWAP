/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatebonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:58:39 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 17:31:44 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

/**
 * 	ra : Put the top node of A at the bottom --> [1][2][3][4] becomes [2][3][4][1]
 * 
 * 	rb : Put the top node of B at the bottom --> [5][6][7] becomes [6][7][5]
 * 
 * 	rr : Put the top node of A and B at their bottom --> [1][2][3][4] and [5][6][7] becomes [2][3][4][1] and [6][7][5]
*/

static void	rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*last;
	
	tmp = *s; //stocking the first node
	last = stack_bottom(*s); //getting the last one
	*s = (*s)->next; //setting the the second as the new top
	tmp->next = NULL; //the old top which is now the last has no next
	last->next = tmp; //adding the new last next to the old last
}

void	ra_bo(t_stack **a)
{
	rotate(a);
}

void	rb_bo(t_stack **b)
{
	rotate(b);
}

void	rr_bo(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
