/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:58:26 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/17 05:56:44 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * 	pa : Push the top node of B on top of A --> [1][2][3][4] [5][6][7] becomes [5][1][2][3][4] [6][7]
 * 		 Do nothing if B is empty
 * 
 * 	pb : Push the top node of A on top of B --> [1][2][3][4] [5][6][7] becomes [2][3][4] [1][5][6][7]
 *  	 Do nothing if A is empty
*/

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;
	
	if (!*src)
		return ;
	tmp = (*src)->next; //stocking the second of B
	(*src)->next = *dst; //setting the next of top B to top A
	*dst = *src; //top A = top B (who has now the old top as next)
	*src = tmp; // putting the second B that we stocked back in first position
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr("pb\n");
}
