#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

int	ft_isordered(t_stack *stack)
{
	int	n;
	t_stack	*sublist;
	
	sublist = stack;
	while(sublist->next)
	{
		n = sublist->value;
		if (n > sublist->next->value)
			return (0);
		sublist = sublist->next;
	}
	return (1);
}