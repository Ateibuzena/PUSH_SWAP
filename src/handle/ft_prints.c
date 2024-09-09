#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

void	ft_print_stack(t_stack *stack)
{
	//ft_printf("Next aux pointer before moving: %p\n", stack->next);
	while (stack)
	{
		ft_printf("value: %d, pos_f: %d, pos_a: %d stack_size: %d, cost_a: %d, cost_b: %d, cost_t: %d, move_a: %s, move_b: %s\n",
		stack->value, stack->pos_f, stack->pos_a, stack->size, stack->cost_a, stack->cost_b, stack->cost_t, stack->move_a, stack->move_b);
		stack = stack->next;
	}
}

void	ft_print_array(int	*array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("a_%d: %d\n", i, array[i]);
		i++;
	}
}