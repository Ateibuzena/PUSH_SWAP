/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:27:37 by azubieta          #+#    #+#             */
/*   Updated: 2024/09/29 18:45:55 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/push_swap_github/pushlibft.h"

void	ft_push(t_stack **source, t_stack **dest)
{
	t_stack	*second_a;
	t_stack	*first_a;

	if (!(*source))
		return ;
	first_a = *source;
	second_a = (*source)->next;
	ft_add_front(dest, first_a);
	*source = second_a;
	first_a = *source;
	ft_inits(source);
	ft_inits(dest);
}

void	ft_push_b(t_stack **source, t_stack **dest)
{
	ft_push(source, dest);
	ft_printf("pb\n");
}

void	ft_push_a(t_stack **source, t_stack **dest)
{
	ft_push(dest, source);
	ft_printf("pa\n");
}
