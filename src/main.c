/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:37:48 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/16 02:17:16 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* is_sorted:
*	Checks if a stack is sorted.
*	Returns 0 if the stack is not sorted, 1 if it is sorted.
*/
int	is_sorted(t_stack *s)
{
	while (s->next)
	{
		if (s->value > s->next->value)
			return (0);
		s = s->next;
	}
	return (1);
}

/* push_swap:
*	Chooses a sorting method depending on the number
*	of values to be sorted.
*/
static void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		sa(a);
	else if (size == 3)
		tiny_sort(a);
	else if (size > 3 && !is_sorted(*a))
		sort(a, b);
}

/* main:
*	Checks if the input is correct, in which case it initializes stacks a and b,
*	assigns each value indexes and sorts the stacks. When sorting is done, frees
*	the stacks and exits.
*/
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		s_size;
	
	if (ac < 2)
		return (1);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	b = NULL;
	a = fill_stack_values(ac, av);
	s_size = get_stack_size(a);
	assing_index(a, s_size + 1);
	push_swap(&a, &b, s_size);
	free(&a);
	free(&b);
	return (0);
}