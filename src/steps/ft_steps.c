/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_steps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:43:32 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/01 18:22:32 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

int	ft_step_one(t_stack **stack_a, t_stack **stack_b)
{
	ft_init_index(stack_a);
	if (ft_isordered((*stack_a)))
		return (0);
	if (ft_stack_size((*stack_a)) > 3)
		(ft_push_b(stack_a, stack_b), ft_push_b(stack_a, stack_b));
	else
	{
		ft_sort_three(stack_a);
		return (0);
	}
	return (1);
}

void	ft_step_two(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	t_stack	*stack_b;
	//t_stack	*node_i;

	node_a = *a;
	stack_b = *b;
	//node_i = ft_immediate_predecessor_down(node_a, stack_b);
	while (node_a)
	{
		ft_init_cost(node_a, stack_b);
		node_a = node_a->next;
	}
	ft_min_cost(a);
}

void	ft_step_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;

	node_a = ft_min_cost(stack_a);
	//ft_printf("antes: %d\n", node_a->cost_b);
	ft_simultaneous_moves(stack_a, stack_b, node_a);
	//ft_printf("dispues: %d\n", node_a->cost_b);
	while (node_a->cost_a)
	{
		if (node_a->move_a && !ft_strncmp(node_a->move_a,
				"e", ft_strlen(node_a->move_a)))
		{
			node_a->cost_a -= 1;
			ft_reverse_a(stack_a);
		}
		else if (node_a->move_a && !ft_strncmp(node_a->move_a,
				"o", ft_strlen(node_a->move_a)))
		{
			node_a->cost_a -= 1;
			ft_rotate_a(stack_a);
		}
	}
	while (node_a->cost_b)
	{
		//ft_printf("bucle infinito: %d\n", node_a->cost_b);
		if (node_a->move_b && !ft_strncmp(node_a->move_b,
				"e", ft_strlen(node_a->move_b)))
		{
			node_a->cost_b -= 1;
			ft_reverse_b(stack_b);
		}
		else if (node_a->move_b && !ft_strncmp(node_a->move_b,
				"o", ft_strlen(node_a->move_b)))
		{
			node_a->cost_b -= 1;
			ft_rotate_b(stack_b);
		}
	}
	ft_push_b(stack_a, stack_b);
}

void	ft_step_four(t_stack **stack_b)
{
	while (ft_max_value((*stack_b))->pos_a != 0)
	{
		if (ft_max_value((*stack_b))->pos_a <= ft_stack_size((*stack_b)) / 2)
			ft_rotate_b(stack_b);
		else
			ft_reverse_b(stack_b);
	}
}

void	ft_step_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_i;
	t_stack	*node_a;
	int		size;

	size = ft_stack_size((*stack_a));
	while (*stack_b)
	{
		node_a = (*stack_b);
		node_i = ft_immediate_predecessor_up(node_a, (*stack_a));
		while (node_i->pos_a != 0)
		{
			if (node_i->pos_a <= size / 2)
				ft_rotate_a(stack_a);
			else
				ft_reverse_a(stack_a);
		}
		ft_push_a(stack_a, stack_b);
	}
}
