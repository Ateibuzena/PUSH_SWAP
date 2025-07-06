/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:45:11 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 10:08:51 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

void	ft_execute_moves_a(t_stack *node_a, t_stack **stack_a)
{
	while (node_a->cost_a)
	{
		if (node_a->move_a && node_a->move_a == 'e')
		{
			node_a->cost_a -= 1;
			ft_reverse_a(stack_a);
		}
		else if (node_a->move_a && node_a->move_a == 'o')
		{
			node_a->cost_a -= 1;
			ft_rotate_a(stack_a);
		}
	}
}

void	ft_execute_moves_b(t_stack *node_a, t_stack **stack_b)
{
	while (node_a->cost_b)
	{
		if (node_a->move_b && node_a->move_b == 'e')
		{
			node_a->cost_b -= 1;
			ft_reverse_b(stack_b);
		}
		else if (node_a->move_b && node_a->move_b == 'o')
		{
			node_a->cost_b -= 1;
			ft_rotate_b(stack_b);
		}
	}
}

void	ft_sync_moves(t_stack **stack_a, t_stack **stack_b, t_stack *node_a)
{
	int common;

	if (node_a->move_a && node_a->move_b && node_a->move_a == node_a->move_b)
	{
		common = (node_a->cost_a < node_a->cost_b) ? node_a->cost_a : node_a->cost_b;
		while (common--)
		{
			if (node_a->move_a == 'e')
				ft_reverse_ab(stack_a, stack_b);
			else if (node_a->move_a == 'o')
				ft_rotate_ab(stack_a, stack_b);
			node_a->cost_a--;
			node_a->cost_b--;
		}
	}
}
