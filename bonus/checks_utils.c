/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:15:34 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 17:27:04 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	nstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

/* free_stack:
*	Frees each element in a given stack and sets the stack pointer to NULL.
*/
void	free_stacks(t_stack **s)
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
void	exit_errors(t_stack **a, t_stack **b)
{
	if (a == NULL || *a)
		free_stacks(a);
	if (b == NULL || *b)
		free_stacks(b);
	ft_printf("%e", "Error\n");
	exit(1);
}

/* ft_atoi:
*   Converts an alphanumeric string of characters into a long integer.
*/
long	ft_atol(const char *str)
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
int	n_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}