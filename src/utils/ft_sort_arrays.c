/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:46:31 by azubieta          #+#    #+#             */
/*   Updated: 2024/09/24 13:48:20 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

int	*ft_sort_array(t_stack *stack, int size, int *array)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (stack)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return (array);
}
