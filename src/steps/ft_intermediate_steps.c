/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intermediate_steps.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:45:11 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/01 18:39:54 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

void	ft_simultaneous_moves(t_stack **stack_a, t_stack **stack_b, t_stack *node_a)
{
	//t_stack	*node_a;
	//int		min;
	int		i;

	//ft_printf("entre en simultaneus move\n");
	//node_a = ft_min_cost((*stack_a));
	//ft_printf("node_a cost_a: %d, cost_b: %d\n", node_a->cost_a, node_a->cost_b);
	i = 0;
	//min = ft_min(node_a->cost_a, node_a->cost_b);
	if (node_a->move_a && node_a->move_b && !ft_strncmp(node_a->move_a,
			node_a->move_b, ft_max(ft_strlen(node_a->move_b), ft_strlen(node_a->move_a))))
	{
		//node_a->cost_t = ft_max(node_a->cost_a, node_a->cost_b);
		//ft_printf("min= %d\n", min);
		while (i < node_a->cost_a && i < node_a->cost_b)
		{
			if (!ft_strncmp(node_a->move_a, "e",
					ft_strlen(node_a->move_a)))
			{
				//ft_printf("entre en doble reverse\n");
				ft_reverse_ab(stack_a, stack_b);
				node_a->cost_a -= 1;
				node_a->cost_b -= 1;
			}
			else if (!ft_strncmp(node_a->move_a, "o", ft_strlen(node_a->move_a)))
			{
				//ft_printf("entre en doble rotate\n");
				ft_rotate_ab(stack_a, stack_b);
				//ft_printf("dentro de simultaneus: %d\n", node_a->cost_b);
				node_a->cost_a -= 1;
				node_a->cost_b -= 1;
			}
			i++;
		}
	}
	/*else
		node_a->cost_t = node_a->cost_a + node_a->cost_b;*/
}

void	ft_update_a(t_stack	*node_a, char *move, int cost)
{
	if (!node_a)
		return ;
	node_a->move_a = ft_strdup(move);
	node_a->cost_a = cost;
}

void	ft_update_b(t_stack	*node_i, t_stack *node_a,
								char *move, int cost)
{
	if (!node_i || !node_a)
		return ;
	node_i->move_b = ft_strdup(move);
	node_a->move_b = ft_strdup(move);
	node_i->cost_b = cost;
	node_a->cost_b = cost;
}

void	ft_update_ab(t_stack *node_max, t_stack *node_a,
								char *move, int cost)
{
	if (!node_max || !node_a)
		return ;
	//node_max->move_a = ft_strdup(move);
	node_a->move_b = ft_strdup(move);
	//node_max->cost_b = cost;
	node_a->cost_b = cost;
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
