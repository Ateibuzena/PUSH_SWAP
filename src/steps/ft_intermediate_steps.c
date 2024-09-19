#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

void	ft_set_moves_and_costs(t_stack *node, int pos, int size)
{
	if (pos <= size / 2)
	{
		node->move_a = "rotate";
		node->cost_a = pos;
	}
	else
	{
		node->move_a = "reverse";
		node->cost_a = size - pos;
	}
}


void	ft_sort_three(t_stack **stack_a)
{
	if (!ft_isordered((*stack_a)))
	{
		if (ft_max_value((*stack_a))->pos_a == 0)
		{
			ft_rotate_a(stack_a);
			if (!ft_isordered((*stack_a)))
				ft_swap_a(stack_a);
		}
		else if (ft_max_value((*stack_a))->pos_a == 1)
		{
			ft_reverse_a(stack_a);
			if (!ft_isordered((*stack_a)))
				ft_swap_a(stack_a);
		}
		else
			ft_swap_a(stack_a);
	}
}
