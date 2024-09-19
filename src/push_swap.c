#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

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
		return (0);
	}
	(ft_init_value(&stack_a, split), ft_free_split(split));
	if (!stack_a)
		return (0);
	if (!ft_step_one(&stack_a, &stack_b))
		return (0);
	while (!ft_isordered(stack_a) && ft_stack_size(stack_a) > 3)
		(ft_step_two(&stack_a, &stack_b), ft_step_three(&stack_a, &stack_b));
	/*ft_print_stack(stack_a);
	ft_printf("stack_b: \n");
	ft_print_stack(stack_b);*/
	(ft_sort_three(&stack_a), ft_step_four(&stack_b));
	(ft_step_five(&stack_a, &stack_b), ft_printf("entraaaaaaaaaa\n"), ft_step_six(&stack_a));
	
	(free(stack_b), ft_free_stack(stack_a));
	return (0);
}