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

/* get_stack_bottom:
*	Returns the last element of the stack.
*/
t_stack	*get_stack_bottom(t_stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

/* get_stack_before_bottom:
*	Returns the second to last element of the stack.
*/
t_stack	*get_stack_before_bottom(t_stack *s)
{
	while (s && s->next && s->next->next)
		s = s->next;
	return (s);
}

/* stack_new:
*	Creates a stack elements with the provided value.
*	Returns the newly created stack element.
*/
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

/* add_stack_bottom:
*	Adds an element to the bottom of a stack.
*/
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

/* get_stack_size:
*	Returns the number of elements in a stack.
*/
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
