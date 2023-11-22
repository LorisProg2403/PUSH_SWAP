/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:47:03 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/22 06:43:13 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* fill_stack_values:
*	Fills stack_a with the provided values.
*	If the values are out of integer range, prints and error and exits the program.
*/
t_stack	*fill_stack_values(char **av)
{
	t_stack	*a;
	long	nb;
	int		i;

	a = NULL;
	nb = 0;
	i = 1;
	while (av[i])
	{
		nb = ft_atolong(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&a, NULL);
		if (i == 1)
			a = stack_new((int)nb);
		else
			stack_add_bottom(&a, stack_new((int)nb));
		i++;
	}
	return (a);
}

/* assign_index:
*	Assigns an index to each value in stack a. This is a convenient way to order
*	the stack because indexes can be checked and compared instead of actual values,
*	which may or may not be adjacent to each other.
*		ex. values:		-3	 0	 9	 2
*		indexes:		[1]	[2]	[4]	[3]
*	The indexes are assigned from highest (stack_size) to lowest (1).
*/
void	assign_index(t_stack *a, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		ptr = a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (highest)
			highest->index = size;
	}
}
