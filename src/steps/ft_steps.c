/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_steps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:43:32 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/12 15:16:26 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

void	ft_assign_costs(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	t_stack	*stack_b;

	node_a = *a;
	stack_b = *b;
	while (node_a)
	{
		ft_init_cost(node_a, stack_b);
		node_a = node_a->next;
	}
	ft_min_cost(a);
}

void	ft_process_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;

	node_a = ft_min_cost(stack_a);
	ft_sync_moves(stack_a, stack_b, node_a);
	(ft_execute_moves_a(node_a, stack_a), ft_execute_moves_b(node_a, stack_b));
	ft_push_b(stack_a, stack_b);
}

void	ft_align_max_b(t_stack **stack_b)
{
	while (ft_max_value((*stack_b))->pos_a != 0)
	{
		if (ft_max_value((*stack_b))->pos_a <= ft_stack_size((*stack_b)) / 2)
			ft_rotate_b(stack_b);
		else
			ft_reverse_b(stack_b);
	}
}

void	ft_move_to_a(t_stack **stack_a, t_stack **stack_b)
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

void	ft_align_min_a(t_stack **stack_a)
{
	while (ft_min_value((*stack_a))->pos_a != 0)
	{
		if (ft_min_value((*stack_a))->pos_a <= ft_stack_size((*stack_a)) / 2)
			ft_rotate_a(stack_a);
		else
			ft_reverse_a(stack_a);
	}
}
