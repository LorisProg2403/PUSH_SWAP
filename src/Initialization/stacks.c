/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:59:23 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/22 06:47:22 by lgaume           ###   ########.fr       */
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
	t_stack	*tail;

	if (!new)
		return ;
	if (!*s)
	{
		*s = new;
		return ;
	}
	tail = get_stack_bottom(*s);
	tail->next = new;
}

int	get_stack_size(t_stack	*s)
{
	int	size;

	size = 0;
	if (!s)
		return (0);
	while (s)
	{
		s = s->next;
		size++;
	}
	return (size);
}
