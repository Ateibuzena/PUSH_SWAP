/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:01:26 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 10:01:55 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

void	ft_align_max_b(t_stack **b)
{
	t_stack *max;
	int size;
	int pos;

	if (!b || !*b)
		return ;

	max = ft_max_value(*b);
	if (!max)
		return ;

	size = ft_stack_size(*b);
	pos = ft_get_position(*b, max);
	while (pos > 0)
	{
		if (pos <= size / 2)
			ft_rotate_b(b);
		else
			ft_reverse_b(b);
		pos = ft_get_position(*b, max);
	}
}

void	ft_align_min_a(t_stack **stack_a)
{
	while (ft_min_value((*stack_a))->pos_a != 0)
	{
		if (ft_min_value((*stack_a))->pos_a <= ft_stack_size((*stack_a)) / 2)
			ft_rotate_a(stack_a);
		else
			ft_reverse_a(stack_a);
	}
}
