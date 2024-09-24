/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:46:26 by azubieta          #+#    #+#             */
/*   Updated: 2024/09/24 13:46:36 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

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

t_stack	*ft_min_cost(t_stack *stack)
{
	int		min;
	t_stack	*node;

	if (!stack)
		return (NULL);
	node = stack;
	min = node->cost_a;
	while (stack)
	{
		if (!ft_strncmp(stack->move_a, stack->move_b, ft_strlen(stack->move_b)))
		{
			stack->cost_t = ft_max(stack->cost_a, stack->cost_b);
			stack->cost_a -= min;
			stack->cost_b -= min;
		}
		else
			stack->cost_t = stack->cost_a + stack->cost_b;
		if (stack->cost_a < min)
		{
			min = stack->cost_a;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_stack	*ft_max_cost(t_stack *stack)
{
	int		max;
	t_stack	*node;
	t_stack	*aux;

	if (!stack)
		return (NULL);
	aux = stack;
	max = aux->cost_a;
	node = aux;
	while (aux)
	{
		if (aux->cost_a > max)
		{
			max = aux->cost_a;
			node = aux;
		}
		aux = aux->next;
	}
	return (node);
}
