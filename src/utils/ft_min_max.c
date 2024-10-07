/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:46:26 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/02 23:43:01 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

t_stack	*ft_min_value(t_stack *stack)
{
	int		min;
	t_stack	*node;
	t_stack	*aux;

	if (!stack)
		return (NULL);
	aux = stack;
	min = aux->value;
	node = aux;
	while (aux)
	{
		if (aux->value < min)
		{
			min = aux->value;
			node = aux;
		}
		aux = aux->next;
	}
	return (node);
}

t_stack	*ft_max_value(t_stack *stack)
{
	int		max;
	t_stack	*node;
	t_stack	*aux;

	if (!stack)
		return (NULL);
	aux = stack;
	max = aux->value;
	node = aux;
	while (aux)
	{
		if (aux->value > max)
		{
			max = aux->value;
			node = aux;
		}
		aux = aux->next;
	}
	return (node);
}

t_stack	*ft_min_cost(t_stack **stack)
{
	int		min;
	t_stack	*node;
	t_stack *aux;

	if (!stack)
		return (NULL);
	node = *stack;
	aux = *stack;
	(*stack) = (*stack)->next;
	//ft_printf("min: %d\n", min);
	while ((*stack))
	{
		/*if ((*stack)->pos_f == 0 || (*stack)->pos_f == 1 || (*stack)->pos_f == 2)
		{
			//ft_print_stack((*stack));
			//ft_printf("stack: %d pos_f: %d\n", (*stack)->value, (*stack)->pos_f);
			(*stack) = (*stack)->next;
		}*/
		if ((*stack)->move_a[0] == (*stack)->move_b[0])
		{
			min = ft_max((*stack)->cost_a, (*stack)->cost_b);
			(*stack)->cost_t = ft_max(node->cost_a, node->cost_b);
		}
		else
		{
			min = (*stack)->cost_a + (*stack)->cost_b;
			(*stack)->cost_t = node->cost_a + node->cost_b;
		}
		//ft_printf("coste node : %d, min: %d\n", (*stack)->cost_t, min);
		if (min < (*stack)->cost_t)
		{
			//ft_printf("kjjhefvkjhfeh\n\n\n");
			node = (*stack);
		}
		(*stack) = (*stack)->next;
	}
	//ft_printf("value: %d, coste node min: %d\n", node->value, node->cost_t);
	*stack = aux;
	return (node);
}

t_stack	*ft_max_cost(t_stack **stack)
{
	int		max;
	t_stack	*node;
	t_stack	*aux;

	if (!stack)
		return (NULL);
	aux = *stack;
	max = aux->cost_t;
	node = aux;
	while (aux)
	{
		if (aux->cost_t > max)
		{
			max = aux->cost_t;
			node = aux;
		}
		aux = aux->next;
	}
	return (node);
}
