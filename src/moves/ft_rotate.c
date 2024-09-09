#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*init;
	int		i;

	if (ft_stack_size(*stack) == 1)
	{
		//fallo tamaño stack
		return ;
	}
	last = *stack;
	init = *stack;
	i = 0;
	*stack = (*stack)->next;
	while (init->next)
	{
		init = init->next;
		init->pos_a = i;
		i++;
	}
	last->pos_a = i;
	init->next = last;
	last->next = NULL;
}

void	ft_rotate_a(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("rotate_a\n");
}

void	ft_rotate_b(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rotate_b\n");
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rotate_ab\n");
}