/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:50:14 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 17:50:43 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push_all_save_three(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = get_stack_size(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b, true);
			pushed++;
		}
		else
			ra(a, true);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(a, b, true);
		pushed++;
	}
}

static void	shift_stack(t_stack **s)
{
	int	lowest_pos;
	int	size;

	size = get_stack_size(*s);
	lowest_pos = get_lowest_index_position(s);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(s, true);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(s, true);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	push_all_save_three(a, b);
	tiny_sort(a);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
