/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:59:45 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 10:00:50 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

void	ft_update(t_stack *node_a, char move, int cost, char c)
{
	if (!node_a)
		return ;
	if (c == 'a')
	{
		node_a->move_a = move;
		node_a->cost_a = cost;
	}
	else if (c == 'b')
	{
		node_a->move_b = move;
		node_a->cost_b = cost;
	}
}

void	ft_init_cost(t_stack *node_a, t_stack *stack_b)
{
	t_stack	*node_i;

	node_i = ft_immediate_predecessor_down(node_a, stack_b);
	if ((node_a->pos_a) <= (node_a->size / 2))
		ft_update(node_a, 'o', node_a->pos_a, 'a');
	else if ((node_a->pos_a) > (node_a->size / 2))
		ft_update(node_a, 'e', node_a->size - node_a->pos_a, 'a');
	if (node_a->value > ft_max_value(stack_b)->value
		|| node_a ->value < ft_min_value(stack_b)->value)
	{
		if (ft_max_value(stack_b)->pos_a <= (stack_b->size / 2))
			ft_update(node_a, 'o', ft_max_value(stack_b)->pos_a, 'b');
		else
			ft_update(node_a, 'e',
				stack_b->size - ft_max_value(stack_b)->pos_a, 'b');
	}
	else if (node_a->value < ft_max_value(stack_b)->value
		&& node_a->value > ft_min_value(stack_b)->value)
	{
		if (node_i->pos_a <= (stack_b->size / 2))
			ft_update(node_a, 'o', node_i->pos_a, 'b');
		else
			ft_update(node_a, 'e', stack_b->size - node_i->pos_a, 'b');
	}
}

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