#ifndef PUSHLIBFT_H
#define PUSHLIBFT_H

# include "/mnt/c/Users/enaat/Documents/Repositorios/42/Libft/libft.h"

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
	char			move_a;
	char			move_b;

	struct s_stack	*next;	
} t_stack;

/*HANDLE*/

//ft_prints.c
void	ft_print_stack(t_stack *stack);

//ft_inits.c
void	ft_init_cost(t_stack *node_a, t_stack *stack_b);
void	ft_init_value(t_stack **stack, char **argv);
void	ft_init_index(t_stack **stack);
void	ft_inits(t_stack **stack);

//ft_stacks.c
t_stack	*ft_new_node(int value);
void	ft_add_back(t_stack **stack, t_stack *node);
void	ft_add_front(t_stack **stack, t_stack *node);
int		ft_stack_size(t_stack *stack);

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

//ft_steps.c
void	ft_optimize_and_execute(t_stack **stack_a, t_stack **stack_b);
void	ft_assign_costs(t_stack **a, t_stack **b);
void	ft_process_move(t_stack **stack_a, t_stack **stack_b);
void	ft_align_max_b(t_stack **stack_b);
void	ft_move_to_a(t_stack **stack_a, t_stack **stack_b);
void	ft_align_min_a(t_stack **stack_a);

//ft_intermediate_steps.c
void	ft_execute_moves_a(t_stack *node_a, t_stack **stack_a);
void	ft_execute_moves_b(t_stack *node_a, t_stack **stack_b);
void	ft_sync_moves(t_stack **stack_a, t_stack **stack_b, t_stack *node_a);
void	ft_update(t_stack *node_a, char move, int cost, char c);
void	ft_sort_three(t_stack **stack_a);

/*UTILS*/

//ft_math.c
int		ft_min(int n1, int n2);
int		ft_max(int n1, int n2);

//ft_sort_arrays.c
int		*ft_sort_array(t_stack *stack, int size, int *array);

//ft_checks_args.c
char	**ft_check_args(int argc, char *argv[]);
int		ft_duplicate_args(char **split, int pos_f);
char	*ft_join_args(int argc, char *argv[]);

//ft_free.c
void 	ft_free_split(char **split);
void	ft_free_stack(t_stack *head);

//ft_isordered.c
int		ft_isordered(t_stack *stack);

//ft_min_max.c
t_stack	*ft_min_value(t_stack *stack);
t_stack	*ft_max_value(t_stack *stack);
t_stack	*ft_min_cost(t_stack **stack);

//ft_immediate_predecessor.c
t_stack	*ft_immediate_predecessor_down(t_stack *node_a, t_stack *stack_b);
t_stack	*ft_immediate_predecessor_up(t_stack *node_a, t_stack *stack_a);

//ft_join.c
char	*ft_join(char const *s1, char const *s2);

/*SRC*/

//push_swap.c
int		ft_prepare_stacks(t_stack **stack_a, t_stack **stack_b);

#endif