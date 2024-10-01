/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:49:03 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/01 18:42:08 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

void	ft_final_step(t_stack **stack_a)
{
	while (ft_min_value((*stack_a))->pos_a != 0)
	{
		if (ft_min_value((*stack_a))->pos_a <= ft_stack_size((*stack_a)) / 2)
			ft_rotate_a(stack_a);
		else
			ft_reverse_a(stack_a);
	}
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
	{
		ft_printf("Error\n");
		return (1);
	}
	(ft_init_value(&stack_a, split), ft_free_split(split));
	if (!stack_a)
		return (0);
	if (!ft_step_one(&stack_a, &stack_b))
		return (0);
	while (!ft_isordered(stack_a) && ft_stack_size(stack_a) > 3)
		(ft_step_two(&stack_a, &stack_b), ft_step_three(&stack_a, &stack_b));
	(ft_sort_three(&stack_a), ft_step_four(&stack_b));

	(ft_step_five(&stack_a, &stack_b), ft_final_step(&stack_a));
	//ft_print_stack(stack_a);
	(free(stack_b), ft_free_stack(stack_a));
	return (0);
}
