/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:44:26 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/12 15:16:21 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (ft_stack_size(*stack) == 1)
		return ;
	third = *stack;
	first = *stack;
	second = (*stack)->next;
	third = third->next->next;
	first->next = third;
	second->next = first;
	*stack = second;
	(*stack)->pos_a = 0;
	(*stack)->next->pos_a = 1;
}

void	ft_swap_a(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
