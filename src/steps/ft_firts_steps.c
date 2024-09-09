#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

int	ft_step_one(t_stack **stack_a, t_stack **stack_b)
{
	ft_init_index(stack_a);
	if (ft_isordered((*stack_a)))
		return (0);
	(ft_push_b(stack_a, stack_b), ft_push_b(stack_a, stack_b));

	return (1);
}

int	ft_step_two(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	t_stack *node_i;
	t_stack	*node_max;
	t_stack	*node_min;
	t_stack	*stack_b;
	
	node_a = *a;
	stack_b = *b;
	node_i = ft_immediate_predecessor(node_a, stack_b);
	node_max = ft_max_value(stack_b);
	node_min = ft_min_value(stack_b);
	while (node_a)
	{
		if ((node_a->pos_a) <= (node_a->size / 2))
		{
			node_a->move_a = "rotate";

			node_a->cost_a = node_a->pos_a;
		}
		else
		{
			node_a->move_a = "reverse";
			node_a->cost_a = node_a->size - node_a->pos_a;
		}
		//AQUI MIRAR COSAS CON GABRIEL
		if (node_a->value > node_max->value || node_a ->value < node_min->value)
		{
			if (node_max->pos_a <= (stack_b->size / 2))
			{
				node_max->move_a = "rotate";
				node_a->move_b = "rotate";
				node_max->cost_b = node_max->pos_a;
            	node_a->cost_b = node_max->cost_b;
			}
			else
			{
				node_max->move_a = "reverse";
				node_a->move_b = "reverse";
				node_max->cost_b = stack_b->size - node_max->pos_a;
            	node_a->cost_b = node_max->cost_b;
			}
		}
		else if (node_a->value < node_max->value && node_a->value > node_min->value)
		{
			if (node_i->pos_a <= (stack_b->size / 2))
			{
				node_i->move_b = "rotate";
				node_a->move_b = "rotate";
				node_i->cost_b = node_i->pos_a;
           		node_a->cost_b = node_i->cost_b;
			}
			else
			{
				node_i->move_b = "reverse";
				node_a->move_b = "reverse";
				node_i->cost_b = stack_b->size - node_i->pos_a;
            	node_a->cost_b = node_i->cost_b;
			}
		}
		node_a = node_a->next;
	}
	return (1);
}

int	ft_step_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;
	int		min;

	//coger el de menor coste total
	node_a = ft_min_cost((*stack_a));
	min = ft_min(node_a->cost_a, node_a->cost_b);
	if (!ft_strncmp(node_a->move_a, node_a->move_b, ft_strlen(node_a->move_b)))
	{
		node_a->cost_t = ft_max(node_a->cost_a, node_a->cost_b);
		node_a->cost_a -= min;
		node_a->cost_b -= min;
		while (min)
		{
			if (!ft_strncmp(node_a->move_a, "reverse", ft_strlen(node_a->move_a)))
				ft_reverse_ab(stack_a, stack_b);
			if (!ft_strncmp(node_a->move_a, "rotate", ft_strlen(node_a->move_a)))
				ft_rotate_ab(stack_a, stack_b);
			min--;
		}
	}
	else
		node_a->cost_t = node_a->cost_a + node_a->cost_b;
	while (node_a->cost_a)
	{
		if (!ft_strncmp(node_a->move_a, "reverse", ft_strlen(node_a->move_a)))
			ft_reverse_a(stack_a);
		if (!ft_strncmp(node_a->move_a, "rotate", ft_strlen(node_a->move_a)))
			ft_rotate_a(stack_a);
		node_a->cost_a -= 1;
	}
	while (node_a->cost_b)
	{
		if (!ft_strncmp(node_a->move_b, "reverse", ft_strlen(node_a->move_b)))
			ft_reverse_b(stack_b);
		if (!ft_strncmp(node_a->move_b, "rotate", ft_strlen(node_a->move_b)))
			ft_rotate_b(stack_b);
		node_a->cost_b -= 1;
	}
	ft_push_b(stack_a, stack_b);
	return (1);
}