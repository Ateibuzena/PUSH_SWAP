/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:06:29 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 10:06:51 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_add_back(t_stack **stack, t_stack *node)
{
	t_stack	*aux;

	aux = *stack;
	if (!aux)
	{
		*stack = node;
		return ;
	}
	while (aux->next)
		aux = aux->next;
	aux->next = node;
}

int	ft_stack_size(t_stack *stack)
{
	int		i;
	t_stack	*sublist;

	i = 0;
	sublist = stack;
	while (sublist)
	{
		i++;
		sublist = sublist->next;
	}
	return (i);
}

void	ft_add_front(t_stack **stack, t_stack *node)
{
	node->next = *stack;
	*stack = node;
}

int	ft_get_position(t_stack *stack, t_stack *target)
{
	int	i = 0;

	while (stack)
	{
		if (stack == target)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}