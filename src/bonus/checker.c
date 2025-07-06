/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:23:26 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 09:14:28 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

int	ft_execute_moves(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "pa\n"))
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(line, "pb\n"))
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(line, "sa\n"))
		ft_swap(stack_a);
	else if (ft_strcmp(line, "sb\n"))
		ft_swap(stack_b);
	else if (ft_strcmp(line, "ss\n"))
		(ft_swap(stack_a), ft_swap(stack_b));
	else
		return (ft_intermediate_moves(line, stack_a, stack_b));
	return (1);
}

int	ft_intermediate_moves(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "ra\n"))
		ft_rotate(stack_a);
	else if (ft_strcmp(line, "rb\n"))
		ft_rotate(stack_b);
	else if (ft_strcmp(line, "rra\n"))
		ft_reverse(stack_a);
	else if (ft_strcmp(line, "rrb\n"))
		ft_reverse(stack_b);
	else if (ft_strcmp(line, "rr\n"))
		(ft_rotate(stack_a), ft_rotate(stack_b));
	else if (ft_strcmp(line, "rrr\n"))
		(ft_reverse(stack_a), ft_reverse(stack_b));
	else
		return (ft_putstr_fd("Error\n", 2), 0);
	return (1);
}

void	ft_init_data(t_pushswap *data, int argc, char *argv[])
{
	char	**split;

	data->stack_a = NULL;
	data->stack_b = NULL;
	split = ft_check_args(argc, argv);
	if (!split || ft_strlen_double(split) == 0)
	{
		if (ft_strlen_double(split) == 0)
			ft_freedouble(split);
		return (ft_putstr_fd("Error\n", 2));
	}
	ft_init_value(&(data->stack_a), split);
	ft_freedouble(split);
}

int	main(int argc, char **argv)
{
	t_pushswap	data;

	if (argc == 1)
		return (0);
	ft_init_data(&data, argc, argv);
	while (1)
	{
		data.line = get_next_line(0);
		if (!data.line)
			break ;
		if (!ft_execute_moves(data.line, &(data.stack_a), &(data.stack_b)))
		{
			free(data.line);
			ft_free_stacks(data.stack_a, data.stack_b);
			return (1);
		}
		free(data.line);
	}
	if (!ft_isordered(data.stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stacks(data.stack_a, data.stack_b);
	return (0);
}
