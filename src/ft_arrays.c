#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

int	*ft_sort_array(t_stack *stack, int size, int *array)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (stack)
	{
		array[i] = stack->value;
		i++;
		stack = stack->next;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
	//ft_print_array(array, size);
	return (array);
}