/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:28:28 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 15:41:18 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	get_commands(void)
{
	char	**commands;
	int		i;
	
	i = 0;
	while (1)
	{
		commands[i] = get_next_line(0);
		if (!commands[i])
			break ;
		i++;
	}
	do_commands(commands);
	ft_free_ptrstr(commands);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	bool	used_split;

	used_split = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = split(av[1], ' ');
		used_split = 1;
	}
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	b = NULL;
	a = fill_stack_values(av);
	if (used_split)
		free_av(av);
	get_commands();
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}