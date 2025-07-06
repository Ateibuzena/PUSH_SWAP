/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:45:53 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 10:07:20 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("v: %d c_a: %d c_b: %d m_a: %c m_b: %c c_t: %d\n",
			stack->value, stack->cost_a, stack->cost_b,
			stack->move_a, stack->move_b, stack->cost_t);
		stack = stack->next;
	}
}
