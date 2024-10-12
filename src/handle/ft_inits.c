/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:26:20 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/07 12:44:00 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/mnt/c/Users/enaat/Documents/Repositorios/42/push_swap/pushlibft.h"

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
		aux->move_a = 'o';
		aux->move_b = 'o';
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
