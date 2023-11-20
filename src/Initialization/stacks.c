/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:59:23 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/20 13:03:34 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*get_stack_bottom(t_stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

t_stack	*get_stack_before_bottom(t_stack *s)
{
	while (s && s->next && s->next->next)
		s = s->next;
	return (s);
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	stack_add_bottom(t_stack **s, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*s)
	{
		*s = new;
		return ;
	}
	last = get_stack_bottom(*s);
	last->next = new;
}

int	get_stack_size(t_stack *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}
