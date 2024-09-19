#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

t_stack	*ft_immediate_predecessor_down(t_stack *node_a, t_stack *stack_b)
{
	t_stack	*aux;
	t_stack	*node;
	int 	diff;
    int 	min_diff;

    if (!node_a || !stack_b)
        return (NULL);
    node = NULL;
    min_diff = 2147483647;
    aux = stack_b;
    while (aux)
    {
        diff = node_a->value - aux->value;
        if (diff > 0 && diff < min_diff)
        {
            min_diff = diff;
            node = aux;
        }
        aux = aux->next;
    }
    return (node);
}

t_stack	*ft_immediate_predecessor_up(t_stack *node_a, t_stack *stack_a)
{
	t_stack	*aux;
	t_stack	*node;
	int 	diff;
    int 	min_diff;

    if (!node_a || !stack_a)
        return (NULL);
    node = NULL;
    min_diff = 2147483647;
    aux = stack_a;
    if (node_a->value > ft_max_value(stack_a)->value)
        return (ft_min_value(stack_a));
    while (aux)
    {
        diff = aux->value - node_a->value;
        if (diff > 0 && diff < min_diff)
        {
            min_diff = diff;
            node = aux;
        }
        aux = aux->next;
    }
    return (node);
}