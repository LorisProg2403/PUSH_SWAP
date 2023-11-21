/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:18:04 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 17:31:10 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

t_stack	*stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

static void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = stack_bottom(*stack);
	tail->next = new;
}

static t_stack	*stack_new(int value)
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

t_stack	*fill_stack(char **av)
{
	t_stack	*a;
	long	nb;
	int		i;

	a = NULL;
	nb = 0;
	i = 1;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_errors(&a, NULL);
		if (i == 1)
			a = stack_new((int)nb);
		else
			stack_add_bottom(&a, stack_new((int)nb));
		i++;
	}
	return (a);
}
