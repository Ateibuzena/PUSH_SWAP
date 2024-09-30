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

#include "/home/azubieta/sgoinfre/azubieta/push_swap_github/pushlibft.h"

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("value: %d\n", stack->value);
		stack = stack->next;
	}
}