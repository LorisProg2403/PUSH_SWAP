/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:58:26 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/30 11:39:13 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * 	pa : 	Push the top node of B on top of A 
 * 			--> [1][2][3][4] [5][6][7] becomes [5][1][2][3][4] [6][7]
 * 		 	Do nothing if B is empty
 * 
 * 	pb : 	Push the top node of A on top of B 
 * 			--> [1][2][3][4] [5][6][7] becomes [2][3][4] [1][5][6][7]
 *  	 	Do nothing if A is empty
*/

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}
