/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isordered.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:46:11 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/07 16:50:04 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

int	ft_isordered(t_stack *stack)
{
	int		n;
	t_stack	*sublist;

	if (!stack)
		return (0);
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
