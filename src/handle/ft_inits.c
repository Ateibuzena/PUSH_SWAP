/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:26:20 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/01 18:22:45 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

void	ft_inits(t_stack **stack)
{
	t_stack	*aux;
	int		i;

	aux = *stack;
	i = 0;
	while (aux)
	{
		aux->pos_a = i;
		i++;
		aux = aux->next;
	}
	aux = *stack;
	while (aux)
	{
		aux->size = i;
		aux->cost_a = 0;
		aux->cost_b = 0;
		aux->cost_t = 0;
		aux->move_a = "o";
		aux->move_b = "o";
		aux = aux->next;
	}
}

void	ft_init_index(t_stack **stack)
{
	int		*array;
	t_stack	*aux;
	int		i;

	array = malloc((*stack)->size * sizeof(int));
	if (!array)
		return ;
	array = ft_sort_array(*stack, (*stack)->size, array);
	aux = *stack;
	while (aux)
	{
		i = 0;
		while (i < (*stack)->size)
		{
			if (aux->value == array[i])
				aux->pos_f = i;
			i++;
		}
		aux = aux->next;
	}
	free(array);
}

void	ft_init_value(t_stack **stack, char **argv)
{
	int			i;
	t_stack		*node;

	i = 0;
	while (argv[i])
	{
		node = ft_new_node(ft_atoi(argv[i]));
		ft_add_back(stack, node);
		node->pos_a = i;
		i++;
	}
	ft_inits(stack);
}

void	ft_init_cost(t_stack *n_a, t_stack *stack_b)
{
	t_stack	*node_i;
	
	node_i = ft_immediate_predecessor_down(n_a, stack_b);
	if ((n_a->pos_a) <= (n_a->size / 2))
		ft_update_a(n_a, "o", n_a->pos_a);
	else if ((n_a->pos_a) > (n_a->size / 2))
		ft_update_a(n_a, "e", n_a->size - n_a->pos_a);
	if (n_a->value > ft_max_value(stack_b)->value
		|| n_a ->value < ft_min_value(stack_b)->value)
	{
		if (ft_max_value(stack_b)->pos_a <= (stack_b->size / 2))
			ft_update_ab(ft_max_value(stack_b), n_a, "o",
				ft_max_value(stack_b)->pos_a);
		else
			ft_update_ab(ft_max_value(stack_b), n_a, "e",
				stack_b->size - ft_max_value(stack_b)->pos_a);
	}
	else if (n_a->value < ft_max_value(stack_b)->value
		&& n_a->value > ft_min_value(stack_b)->value)
	{
		if (node_i->pos_a <= (stack_b->size / 2))
			ft_update_b(node_i, n_a, "o", node_i->pos_a);
		else
			ft_update_b(node_i, n_a, "e", stack_b->size - node_i->pos_a);
	}
	//ft_min_cost(&n_a);
}
