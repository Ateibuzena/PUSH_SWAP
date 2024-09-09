#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (ft_stack_size(*stack) == 1)
	{
		//fallo tamaño stack
		return ;
	}
	third = *stack;
	first = *stack;
	second = (*stack)->next;
	third = third->next->next;
	first->next = third;
	second->next = first;
	*stack = second;
	(*stack)->pos_a = 0;
	(*stack)->next->pos_a = 1;
}

void	ft_swap_a(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("swap_a\n");
}

void	ft_swap_b(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("swap_b\n");
}

void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("swap_ab\n");
}
