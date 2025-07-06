/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:49:03 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 10:15:58 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlibft.h"

int	main(int argc, char *argv[])
{
	t_pushswap	data;
	char		**split;

	if (argc == 1)
		return (0);
	data.stack_a = NULL;
	data.stack_b = NULL;
	split = ft_check_args(argc, argv);
	if (!split || !split[0])
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_init_value(&data.stack_a, split);
	ft_freedouble(split);
	if (!data.stack_a || !ft_prepare_stacks(&data.stack_a, &data.stack_b))
		return (ft_free_stack(data.stack_a), 0);
	while (!ft_isordered(data.stack_a) && ft_stack_size(data.stack_a) > 3)
	{
		ft_assign_costs(&data.stack_a, &data.stack_b);
		ft_process_move(&data.stack_a, &data.stack_b);
	}
	ft_sort_three(&data.stack_a);
	ft_align_max_b(&data.stack_b);
	ft_move_to_a(&data.stack_a, &data.stack_b);
	ft_align_min_a(&data.stack_a);
	ft_free_stacks(data.stack_a, data.stack_b);
	return (0);
}
