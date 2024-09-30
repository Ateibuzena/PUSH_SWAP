/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:43:39 by azubieta          #+#    #+#             */
/*   Updated: 2024/09/29 18:45:57 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/push_swap_github/pushlibft.h"

void	ft_reverse(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;
	t_stack	*init;
	int		i;

	if (ft_stack_size(*stack) == 1)
		return ;
	i = 1;
	init = *stack;
	while (init->next->next)
	{
		init->pos_a = i;
		init = init->next;
		i++;
	}
	prev = init;
	prev->pos_a = i;
	last = prev->next;
	prev->next = NULL;
	last->pos_a = 0;
	last->next = *stack;
	*stack = last;
}

void	ft_reverse_a(t_stack **stack_a)
{
	ft_reverse(stack_a);
	ft_printf("rra\n");
}

void	ft_reverse_b(t_stack **stack_b)
{
	ft_reverse(stack_b);
	ft_printf("rrb\n");
}

void	ft_reverse_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	ft_printf("rrr\n");
}
