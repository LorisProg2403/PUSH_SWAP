/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:58:44 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/30 11:40:58 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * 	sa : 	swap the first two nodes in A 
 * 			--> [1][2][3][4] becomes [2][1][3][4]
 * 		 	do nothing if ther is only one or no elements
 * 
 * 	sb : 	swap the first two nodes in B 
 * 			--> [5][6][7] becomes [6][5][7]
 * 		 	do nothing if ther is only one or no elements
 * 
 * 	ss : 	swap the first two nodes of both A and B 
 * 			--> [1][2][3][4] and [5][6][7] becomes [2][1][3][4] and [6][5][7]
*/

static void	swap(t_stack *s)
{
	int	tmp;

	if (!s || !s->next)
		return ;
	tmp = s->value;
	s->value = s->next->value;
	s->next->value = tmp;
	tmp = s->index;
	s->index = s->next->index;
	s->next->index = tmp;
}

void	sa(t_stack **a, bool print)
{
	swap(*a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool print)
{
	swap(*b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(*a);
	swap(*b);
	if (print)
		ft_printf("ss\n");
}
