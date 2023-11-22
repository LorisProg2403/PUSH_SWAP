/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:05:18 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/22 06:44:39 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* arg_is_number:
*   Checks if the argument is a number. +1 1 and -1 are all valid numbers.
*   Return: 1 if the argument is a number, 0 if not.
*/
static bool	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1])
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] && !ft_isdigit(av[i]))
		return (false);
	return (true);
}

/* have_duplicates:
*   Checks if the argument list has duplicate numbers.
*   Return: 1 if a duplicate is found, 0 if there are none.
*/
static bool	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

/* arg_is_zero:
*   Checks the argument is a 0 to avoid 0 +0 -0 duplicates
*	and 0 0000 +000 -00000000 too.
*   Return: 1 if the argument is a zero, 0 if it contains
*	anything else than a zero.
*/
static bool	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i])
		return (false);
	return (true);
}

/* is_correct_input:
*   Checks if the given arguments are all numbers, without duplicates.
*   Return: 1 if the arguments are valid, 0 if not.
*/
bool	is_correct_input(char **av)
{
	int	i;
	int	zeros;

	zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (false);
		zeros += arg_is_zero(av[i]);
		i++;
	}
	if (zeros > 1)
		return (false);
	if (have_duplicates(av))
		return (false);
	return (true);
}
