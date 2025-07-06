/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:46:26 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 11:07:26 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

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
	t_stack	*node;
	t_stack	*aux;
	int		max;

	if (!stack)
		return (NULL);
	aux = stack;
	node = aux;
	max = aux->value;
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

t_stack	*ft_min_cost(t_stack **a)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		cost_current;
	int		cost_cheapest;

	current = *a;
	cheapest = current;
	while (current)
	{
		if (current->move_a == current->move_b)
			cost_current = ft_max(current->cost_a, current->cost_b);
		else
			cost_current = current->cost_a + current->cost_b;
		if (cheapest->move_a == cheapest->move_b)
			cost_cheapest = ft_max(cheapest->cost_a, cheapest->cost_b);
		else
			cost_cheapest = cheapest->cost_a + cheapest->cost_b;
		if (cost_current < cost_cheapest)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
