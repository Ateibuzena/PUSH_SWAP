/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:23:26 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/23 18:46:13 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

char	*ft_clean_sentence(char *str)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	ptr = malloc((len + 1) * sizeof(char));
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	free(str);
	return (ptr);
}

int	ft_execute_bonus_moves(char **buffer,
		int index, t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	ret;

	i = 0;
	while (i < index)
	{
		buffer[i] = ft_clean_sentence(buffer[i]);
		if (ft_strcmp(buffer[i], "pa"))
			ft_push(stack_b, stack_a);
		else if (ft_strcmp(buffer[i], "pb"))
			ft_push(stack_a, stack_b);
		else if (ft_strcmp(buffer[i], "sa"))
			ft_swap(stack_a);
		else if (ft_strcmp(buffer[i], "sb"))
			ft_swap(stack_b);
		else
			ret = ft_execute_intermediate_moves(buffer[i], stack_a, stack_b);
		i++;
	}
	return (ret);
}

int	ft_execute_intermediate_moves(char *buffer,
	t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(buffer, "ra"))
		ft_rotate(stack_a);
	else if (ft_strcmp(buffer, "rb"))
		ft_rotate(stack_b);
	else if (ft_strcmp(buffer, "rra"))
		ft_reverse(stack_a);
	else if (ft_strcmp(buffer, "rrb"))
		ft_reverse(stack_b);
	else if (ft_strcmp(buffer, "rr"))
		(ft_rotate(stack_a), ft_rotate(stack_b));
	else if (ft_strcmp(buffer, "rrr"))
		(ft_reverse(stack_a), ft_reverse(stack_b));
	else
		return (0);
	return (1);
}

void	ft_init_data(t_pushswap **data, int argc, char *argv[])
{
	(*data) = (t_pushswap *)malloc(sizeof(t_pushswap));
	if (!data)
		return ;
	(*data)->max = 10000;
	(*data)->buffer = (char **)malloc((*data)->max * sizeof(char *));
	if (!data)
		return ;
	(*data)->stack_a = NULL;
	(*data)->stack_b = NULL;
	(*data)->index = 0;
	(*data)->split = ft_check_args(argc, argv);
	(ft_init_value(&((*data)->stack_a), (*data)->split));
	ft_free_split((*data)->split);
	while (1)
	{
		(*data)->line = get_next_line(0);
		if ((*data)->line == NULL)
			break ;
		(*data)->buffer[(*data)->index] = (*data)->line;
		(*data)->index++;
	}
	(*data)->buffer[(*data)->index] = NULL;
}

int	main(int argc, char *argv[])
{
	t_pushswap	*data;

	if (argc == 1)
		return (0);
	ft_init_data(&data, argc, argv);
	if (!data | !data->buffer | !data->split)
		return (ft_printf("Error\n"), 1);
	if (!ft_execute_bonus_moves(data->buffer,
			data->index, &(data->stack_a), &(data->stack_b)))
	{
		(ft_free_split(data->buffer), ft_free_stack(data->stack_a));
		(ft_free_stack(data->stack_b), free(data));
		return (ft_printf("Error\n"), 1);
	}
	if (ft_isordered(data->stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	(ft_free_split(data->buffer), ft_free_stack(data->stack_a));
	(ft_free_stack(data->stack_b), free(data));
	return (0);
}
