/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:15:27 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 10:15:37 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

int	ft_prepare_stacks(t_stack **stack_a, t_stack **stack_b)
{
	ft_init_index(stack_a);
	if (ft_isordered((*stack_a)))
		return (0);
	if (ft_stack_size((*stack_a)) > 3)
		(ft_push_b(stack_a, stack_b), ft_push_b(stack_a, stack_b));
	else
	{
		ft_sort_three(stack_a);
		return (0);
	}
	return (1);
}
