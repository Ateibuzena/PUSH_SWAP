/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:49:03 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/23 18:47:31 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlibft.h"

int	ft_prepare_stacks(t_stack **stack_a, t_stack **stack_b)
{
	ft_init_index(stack_a);
	if (ft_isordered((*stack_a)))
		return (0);
	if (ft_stack_size((*stack_a)) > 3)
		(ft_push_b(stack_a, stack_b), ft_push_b(stack_a, stack_b));
	else
	{
		ft_sort_three(stack_a);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**split;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	split = ft_check_args(argc, argv);
	if (!split)
		return (ft_printf("Error\n"), 1);
	(ft_init_value(&stack_a, split), ft_free_split(split));
	if (!stack_a || !ft_prepare_stacks(&stack_a, &stack_b))
		return (ft_free_stack(stack_a), 0);
	while (!ft_isordered(stack_a) && ft_stack_size(stack_a) > 3)
	{
		ft_assign_costs(&stack_a, &stack_b);
		ft_process_move(&stack_a, &stack_b);
	}
	(ft_sort_three(&stack_a), ft_align_max_b(&stack_b));
	(ft_move_to_a(&stack_a, &stack_b), ft_align_min_a(&stack_a));
	(ft_free_stack(stack_b), ft_free_stack(stack_a));
	return (0);
}
