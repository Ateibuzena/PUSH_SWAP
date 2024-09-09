#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

t_stack	*ft_min_value(t_stack *stack)
{
	int		min;
	t_stack	*node;
	t_stack	*aux;

	if (!stack)
		return (NULL);
	aux = stack;
	min = aux->value;
	node = aux;
	while(aux)
	{
		
		if(aux->value < min)
		{
			min = aux->value;
			node = aux;
		}
		aux = aux->next;
	}
	return (node);
}

t_stack	*ft_max_value(t_stack *stack)
{
	int		max;
	t_stack	*node;
	t_stack	*aux;

	if (!stack)
		return (NULL);
	aux = stack;
	max = aux->value;
	node = aux;
	while(aux)
	{
		
		if(aux->value > max)
		{
			max = aux->value;
			node = aux;
		}
		aux = aux->next;
	}
	return (node);
}

t_stack	*ft_min_cost(t_stack *stack)
{
	int		min;
	t_stack	*node;
	t_stack	*aux;

	if (!stack)
		return (NULL);
	aux = stack;
	min = aux->cost_a;
	node = aux;
	while(aux)
	{
		if (!ft_strncmp(aux->move_a, aux->move_b, ft_strlen(aux->move_b)))
		{
			aux->cost_t = ft_max(aux->cost_a, aux->cost_b);
			aux->cost_a -= min;
			aux->cost_b -= min;
		}
		else
			aux->cost_t = aux->cost_a + aux->cost_b;
		
		if(aux->cost_a < min)
		{
			min = aux->cost_a;
			node = aux;
		}
		aux = aux->next;
	}
	return (node);
}

t_stack	*ft_max_cost(t_stack *stack)
{
	int		max;
	t_stack	*node;
	t_stack	*aux;

	if (!stack)
		return (NULL);
	aux = stack;
	max = aux->cost_a;
	node = aux;
	while(aux)
	{
		
		if(aux->cost_a > max)
		{
			max = aux->cost_a;
			node = aux;
		}
		aux = aux->next;
	}
	return (node);
}


int	ft_min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}