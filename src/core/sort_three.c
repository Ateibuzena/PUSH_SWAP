/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:02:14 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 10:02:45 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

void	ft_sort_three(t_stack **stack_a)
{
	if (!ft_isordered((*stack_a)))
	{
		if (ft_max_value((*stack_a))->pos_a == 0)
		{
			ft_rotate_a(stack_a);
			if (!ft_isordered((*stack_a)))
				ft_swap_a(stack_a);
		}
		else if (ft_max_value((*stack_a))->pos_a == 1)
		{
			ft_reverse_a(stack_a);
			if (!ft_isordered((*stack_a)))
				ft_swap_a(stack_a);
		}
		else
			ft_swap_a(stack_a);
	}
}
