#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

void	ft_push(t_stack **source, t_stack **dest)
{
	t_stack	*second_a;
	t_stack	*first_a;
	t_stack	*first_b;
	int		i;

	if (!(*source))
		return ;
	first_a = *source;
	second_a = (*source)->next;
	i = 0;
	ft_add_front(dest, first_a);
	first_b = *dest;
	while (first_b)
	{
		first_b->pos_a = i;
		first_b = first_b->next;
		i++;
	}
	*source = second_a;
	
	first_a = *source;
	i = 0;
	while (first_a)
	{
		first_a->pos_a = i;
		first_a = first_a->next;
		i++;
	}
	ft_init_size(source);
	ft_init_size(dest);
}

void	ft_push_b(t_stack **source, t_stack **dest)
{
	ft_push(source, dest);
	ft_printf("pb\n");
}

void	ft_push_a(t_stack **source, t_stack **dest)
{
	ft_push(dest, source);
	ft_printf("pa\n");
}
