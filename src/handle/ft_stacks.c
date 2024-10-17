/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:24:21 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/12 15:16:10 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

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
