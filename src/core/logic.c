/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:03:05 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 10:04:22 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

void	ft_process_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;

	node_a = ft_min_cost(stack_a);
	ft_sync_moves(stack_a, stack_b, node_a);
	(ft_execute_moves_a(node_a, stack_a), ft_execute_moves_b(node_a, stack_b));
	ft_push_b(stack_a, stack_b);
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
