/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intermediate_steps.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:45:11 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/12 15:16:24 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

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
	int		i;

	i = 0;
	if (node_a->move_a && node_a->move_b && node_a->move_a == node_a->move_b)
	{
		while (i < node_a->cost_a && i < node_a->cost_b)
		{
			if (node_a->move_a == 'e')
			{
				ft_reverse_ab(stack_a, stack_b);
				node_a->cost_a -= 1;
				node_a->cost_b -= 1;
			}
			else if (node_a->move_a == 'o')
			{
				ft_rotate_ab(stack_a, stack_b);
				node_a->cost_a -= 1;
				node_a->cost_b -= 1;
			}
			i++;
		}
	}
}

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
