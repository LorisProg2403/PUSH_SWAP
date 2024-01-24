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
