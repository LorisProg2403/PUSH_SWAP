/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:38:44 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/22 06:45:44 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include "../libft/include/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Initialization */

t_stack		*fill_stack_values(char **av);
void		assign_index(t_stack *a, int ac);

/* Sorting algo */

int			is_sorted(t_stack *s);
void		tiny_sort(t_stack **s);
void		sort(t_stack **a, t_stack **b);

/* Position */

int			get_lowest_index_position(t_stack **s);
void		get_target_position(t_stack **a, t_stack **b);

/* Cost */

void		get_cost(t_stack **a, t_stack **b);
void		do_cheapest_move(t_stack **a, t_stack **b);

/* Move */

void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operations */

void		pa(t_stack **a, t_stack **b, bool print);
void		pb(t_stack **a, t_stack **b, bool print);
void		sa(t_stack **a, bool print);
void		sb(t_stack **b, bool print);
void		ss(t_stack **a, t_stack **b, bool print);
void		ra(t_stack **a, bool print);
void		rb(t_stack **b, bool print);
void		rr(t_stack **a, t_stack **b, bool print);
void		rra(t_stack **a, bool print);
void		rrb(t_stack **b, bool print);
void		rrr(t_stack **a, t_stack **b, bool print);

/* Stacks Functions */

t_stack		*get_stack_bottom(t_stack *s);
t_stack		*get_stack_before_bottom(t_stack *s);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **s, t_stack *new);
int			get_stack_size(t_stack *s);

/* Utils */

void		free_stack(t_stack **s);
long		ft_atolong(const char *str);
int			nb_abs(int nb);
char		**split(char *s, char c);

/* Error */

void		exit_error(t_stack **a, t_stack **b);

/* Input Check */

bool		is_correct_input(char **av);
int			nbstr_cmp(const char *s1, const char *s2);

#endif //PUSH_SWAP_H
