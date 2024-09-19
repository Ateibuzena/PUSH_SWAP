#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

void	ft_init_size(t_stack **stack)
{
	t_stack	*aux;
	int		i;

	aux = *stack;
	i = 0;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	aux = *stack;
	while (aux)
	{
		aux->size = i;
		aux->cost_a = 0;
		aux->cost_b = 0;
		aux->cost_t = 0;
		aux->move_a = "rotate";
		aux = aux->next;
	}
}

void ft_init_index(t_stack **stack)
{	
	int		*array;
	t_stack	*aux;
	int		i;

	array = malloc((*stack)->size * sizeof(int));
	if (!array)
		return;
	array = ft_sort_array(*stack, (*stack)->size, array);
	aux = *stack;
	while (aux)
	{
		i = 0;
		while (i < (*stack)->size)
		{
			if (aux->value == array[i])
				aux->pos_f = i;
			i++;
		}
		aux = aux->next;
	}
	free(array);
}

void	ft_init_value(t_stack **stack, char **argv)
{
	int			i;
	t_stack		*node;

	i = 0;
	while (argv[i])
	{
		node = ft_new_node(ft_atoi(argv[i]));
		ft_add_back(stack, node);
		node->pos_a = i;
		i++;
	}
	ft_init_size(stack);
}
