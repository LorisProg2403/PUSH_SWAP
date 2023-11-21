/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:28:28 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/21 17:32:40 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

static int	do_commands(char *commands, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(commands, "pa\n"))
		pa_bo(a, b);
	else if (!ft_strcmp(commands, "pb\n"))
		pb_bo(a, b);
	else if (!ft_strcmp(commands, "sa\n"))
		sa_bo(a);
	else if (!ft_strcmp(commands, "sb\n"))
		sb_bo(b);
	else if (!ft_strcmp(commands, "ss\n"))
		ss_bo(a, b);
	else if (!ft_strcmp(commands, "ra\n"))
		ra_bo(a);
	else if (!ft_strcmp(commands, "rb\n"))
		rb_bo(b);
	else if (!ft_strcmp(commands, "rr\n"))
		rr_bo(a, b);
	else if (!ft_strcmp(commands, "rra\n"))
		rra_bo(a);
	else if (!ft_strcmp(commands, "rrb\n"))
		rrb_bo(b);
	else if (!ft_strcmp(commands, "rrr\n"))
		rrr_bo(a, b);
	else
		return (1);
	return (0);
}

static void	loop_commands(char **commands, t_stack **a, t_stack **b)
{
	int	i;
	int	check;
	
	i = 0;
	while (commands[i])
	{
		check = do_commands(commands[i],a ,b);
		if (check)
		{
			ft_printf("%e", "Failed to do commands\n");
			return ;
		}
		i++;
	}
}

static void	get_commands(t_stack **a, t_stack **b)
{
	char	**commands;
	int		i;
	
	i = 0;
	commands = malloc(sizeof(char *) * 11000);
	while (1)
	{
		commands[i] = get_next_line(0);
		if (!commands[i])
			break ;
		i++;
	}
	loop_commands(commands, a, b);
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
		av = splitbonus(av[1], ' ');
		used_split = 1;
	}
	if (!is_correct_inputs(av))
		exit_errors(NULL, NULL);
	b = NULL;
	a = fill_stack(av);
	if (used_split)
		ft_free_ptrstr(av);
	get_commands(&a, &b);
	if (issorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(&a);
	free_stacks(&b);
	return (0);
}