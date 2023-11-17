/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:58:33 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/17 05:57:17 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * 	rra : Put the bottom node to the top of A --> [1][2][3][4] becomes [4][1][2][3]
 * 
 * 	rrb : Put the bottom node to the top of B --> [5][6][7] becomes [7][5][6]
 * 
 * 	rrr : Put both the bottom node of A and B to the top --> [1][2][3][4] and [5][6][7] becomes [4][1][2][3] and [7][5][6]
*/

static void	reverse_rotate(t_stack **s)
{
	t_stack	*last;
	t_stack	*before_last;
	
	last = get_stack_bottom(*s);
	before_last = get_stack_before_bottom(*s);
	before_last->next = NULL;
	last->next = *s;
	*s = last;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putstr("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr("rrr\n");
}
