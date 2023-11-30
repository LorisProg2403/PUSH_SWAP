/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:28:28 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/30 11:48:04 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

static int	do_commands(char *commands, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(commands, "pa\n"))
		pa(a, b, false);
	else if (!ft_strcmp(commands, "pb\n"))
		pb(a, b, false);
	else if (!ft_strcmp(commands, "sa\n"))
		sa(a, false);
	else if (!ft_strcmp(commands, "sb\n"))
		sb(b, false);
	else if (!ft_strcmp(commands, "ss\n"))
		ss(a, b, false);
	else if (!ft_strcmp(commands, "ra\n"))
		ra(a, false);
	else if (!ft_strcmp(commands, "rb\n"))
		rb(b, false);
	else if (!ft_strcmp(commands, "rr\n"))
		rr(a, b, false);
	else if (!ft_strcmp(commands, "rra\n"))
		rra(a, false);
	else if (!ft_strcmp(commands, "rrb\n"))
		rrb(b, false);
	else if (!ft_strcmp(commands, "rrr\n"))
		rrr(a, b, false);
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
		check = do_commands(commands[i], a, b);
		if (check)
		{
			ft_printf("%e%e%e", "Failed to do command : ", commands[i], "\n");
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

	used_split = (!(ac == 1 || (ac == 2 && !av[1][0])) && ac == 2);
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	b = NULL;
	a = fill_stack_values(av);
	if (used_split)
		ft_free_ptrstr(av);
	get_commands(&a, &b);
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
