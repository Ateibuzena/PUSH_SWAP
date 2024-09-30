/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:43:59 by azubieta          #+#    #+#             */
/*   Updated: 2024/09/29 18:45:59 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/push_swap_github/pushlibft.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*init;
	int		i;

	if (ft_stack_size(*stack) == 1)
		return ;
	last = *stack;
	init = *stack;
	i = 0;
	*stack = (*stack)->next;
	while (init->next)
	{
		init = init->next;
		init->pos_a = i;
		i++;
	}
	last->pos_a = i;
	init->next = last;
	last->next = NULL;
}

void	ft_rotate_a(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
