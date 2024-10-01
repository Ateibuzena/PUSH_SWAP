/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:45:53 by azubieta          #+#    #+#             */
/*   Updated: 2024/09/29 18:45:53 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("value: %d cost_a: %d cost_b: %d move_a: %s move_b: %s cost_t: %d\n", stack->value, stack->cost_a, stack->cost_b, stack->move_a, stack->move_b, stack->cost_t);
		stack = stack->next;
	}
}