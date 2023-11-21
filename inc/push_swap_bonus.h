#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

t_stack		*fill_stack(char **av);
int			issorted(t_stack *s);

void		pa_bo(t_stack **a, t_stack **b);
void		pb_bo(t_stack **a, t_stack **b);
void		sa_bo(t_stack **a);
void		sb_bo(t_stack **b);
void		ss_bo(t_stack **a, t_stack **b);
void		ra_bo(t_stack **a);
void		rb_bo(t_stack **b);
void		rr_bo(t_stack **a, t_stack **b);
void		rra_bo(t_stack **a);
void		rrb_bo(t_stack **b);
void		rrr_bo(t_stack **a, t_stack **b);

void		free_stacks(t_stack **s);
long		ft_atol(const char *str);
int			n_abs(int nb);
char		**splitbonus(char *s, char c);
void		exit_errors(t_stack **a, t_stack **b);
int			is_correct_inputs(char **av);
int         nstr_cmp(const char *s1, const char *s2);
t_stack     *stack_bottom(t_stack *stack);
t_stack	    *stack_before_bottom(t_stack *stack);

#endif