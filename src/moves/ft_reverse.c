#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

void	ft_reverse(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;
	t_stack	*init;
	int		i;

	if (ft_stack_size(*stack) == 1)
	{
		//fallo tamaño stack
		return ;
	}
	i = 1;
	init = *stack;
	while (init->next->next)
	{
		init->pos_a = i;
		init = init->next;
		i++;
	}
	prev = init;
	prev->pos_a = i;
	last = prev->next;
	prev->next = NULL;
	last->pos_a = 0;
	//paso importante que hace que un nodo apunte a lo que apuntaba otro
	last->next = *stack;
	*stack = last;
}

void	ft_reverse_a(t_stack **stack_a)
{
	ft_reverse(stack_a);
	ft_printf("rra\n");
}

void	ft_reverse_b(t_stack **stack_b)
{
	ft_reverse(stack_b);
	ft_printf("rrb\n");
}

void	ft_reverse_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	ft_printf("rrr\n");
}