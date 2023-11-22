/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:01:20 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/22 06:48:31 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* free_stack:
*	Frees each element in a given stack and sets the stack pointer to NULL.
*/
void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s || !(*s))
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		(*s)->value = 0;
		free(*s);
		*s = tmp;
	}
	*s = NULL;
}

/* exit_error:
*   Writes "Error\n" to the standard output after freeing stack a and b.
*	Exits with standard error code 1.
*/
void	exit_error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a)
		free_stack(a);
	if (b == NULL || *b)
		free_stack(b);
	ft_printf("%e", "Error\n");
	exit(1);
}

/* ft_atoi:
*   Converts an alphanumeric string of characters into a long integer.
*/
long	ft_atolong(const char *str)
{
	long	nb;
	int		is_neg;
	int		i;

	nb = 0;
	is_neg = 1;
	i = 0;
	if (is_sign(str[i]))
	{
		if (str[i] == '-')
			is_neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * is_neg);
}

/* nb_abs:
*	Returns the absolute value of a given number.
*	The absolute value of a number is used to measure the distance of that
*	number from 0, whether it is positive or negative (abs value of -6 is 6).
*/
int	nb_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
