/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isordered.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:46:11 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/12 15:16:38 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

int	ft_isordered(t_stack *stack)
{
	int		n;
	t_stack	*sublist;

	sublist = stack;
	while (sublist->next)
	{
		n = sublist->value;
		if (n > sublist->next->value)
			return (0);
		sublist = sublist->next;
	}
	return (1);
}
