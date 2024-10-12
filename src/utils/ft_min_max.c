/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:46:26 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/07 12:45:39 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/mnt/c/Users/enaat/Documents/Repositorios/42/push_swap/pushlibft.h"

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
	t_stack	*aux;

	node = *stack;
	aux = *stack;
	(*stack) = (*stack)->next;
	while ((*stack))
	{
		if ((*stack)->move_a == (*stack)->move_b)
		{
			min = ft_max((*stack)->cost_a, (*stack)->cost_b);
			(*stack)->cost_t = ft_max(node->cost_a, node->cost_b);
		}
		else
		{
			min = (*stack)->cost_a + (*stack)->cost_b;
			(*stack)->cost_t = node->cost_a + node->cost_b;
		}
		if (min < (*stack)->cost_t)
			node = (*stack);
		(*stack) = (*stack)->next;
	}
	*stack = aux;
	return (node);
}
