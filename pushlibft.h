#ifndef PUSHLIBFT_H
#define PUSHLIBFT_H

# include "/home/azubieta/sgoinfre/azubieta/libft/libft.h"

typedef struct s_stack
{
	int				max;
	int				min;
	int				pos_a;
	int				pos_f;
	int				cost_a;
	int				cost_b;
	int				cost_t;
	int				value;
	int				size;
	char			*move_a;
	char			*move_b;

	struct s_stack	*next;	
} t_stack;

//ft_inits.c
void	ft_init_value(t_stack **stack, int argc, char **argv);
void	ft_init_index(t_stack **stack);
void	ft_init_size(t_stack **stack);

//ft_stacks.c
t_stack	*ft_new_node(int value);
void	ft_add_back(t_stack **stack, t_stack *node);
void	ft_add_front(t_stack **stack, t_stack *node);
int		ft_stack_size(t_stack *stack);

//ft_arrays.c
int		*ft_sort_array(t_stack *stack, int size, int *array);


/*HANDLE*/

//ft_prints.c
void	ft_print_array(int	*array, int size);
void	ft_print_stack(t_stack *stack);

//ft_checks.c
char	**ft_one_argument(char *argv[]);
int		ft_check_arguments(int argc, char *argv[]);

//ft_errors.c
int	ft_argc_error(void);
int	ft_argv_error(void);
int	ft_argv_duplicate(void);

/*MOVES*/

//ft_reverse.c
void	ft_reverse(t_stack **stack);
void	ft_reverse_a(t_stack **stack_a);
void	ft_reverse_b(t_stack **stack_b);
void	ft_reverse_ab(t_stack **stack_a, t_stack **stack_b);

//ft_rotate.c
void	ft_rotate(t_stack **stack);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);

//ft_swap.c
void	ft_swap(t_stack **stack);
void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b);

//ft_push.c
void	ft_push(t_stack **stack_a, t_stack **stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_b, t_stack **stack_a);

/*STEPS*/

//ft_firts_steps.c
int		ft_step_one(t_stack **stack_a, t_stack **stack_b);
int		ft_step_two(t_stack **a, t_stack **b);
int		ft_step_three(t_stack **stack_a, t_stack **stack_b);

/*UTILS*/

//ft_isordered.c
int		ft_isordered(t_stack *stack);

//ft_min_max.c
t_stack	*ft_min_value(t_stack *stack);
t_stack	*ft_max_value(t_stack *stack);
t_stack	*ft_min_cost(t_stack *stack);
t_stack	*ft_max_cost(t_stack *stack);
int		ft_min(int n1, int n2);
int		ft_max(int n1, int n2);

//ft_immediate_predecessor.c
t_stack	*ft_immediate_predecessor(t_stack *node_a, t_stack *stack_b);

#endif