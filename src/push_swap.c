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
		return (ft_printf("Error\n"));
	ft_init_value(&stack_a, split);
	if (!stack_a)
		return (0);
	if (!ft_step_one(&stack_a, &stack_b))
	{
		ft_printf("The stack is already ordered\n");
		//ft_print_stack(stack_a);
		return (0);
	
	}
	ft_printf("PASO UNO\n");

	while (!ft_isordered(stack_a) && ft_stack_size(stack_a) > 3)
	{
		ft_printf("PASO DOS\n");
		ft_step_two(&stack_a, &stack_b);
		
		ft_printf("stack_a:\n");
		ft_print_stack(stack_a);
		ft_printf("stack_b\n");
		ft_print_stack(stack_b);
		
		ft_printf("PASO TRES\n");
		ft_step_three(&stack_a, &stack_b);

		ft_printf("stack_a:\n");
		ft_print_stack(stack_a);
		ft_printf("stack_b\n");
		ft_print_stack(stack_b);
	}



	
	/*ft_reverse_a(&stack_a);
	ft_print_stack(stack_a);
	
	ft_rotate_a(&stack_a);
	ft_print_stack(stack_a);
	
	ft_swap_a(&stack_a);
	ft_print_stack(stack_a);
	
	ft_push_b(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	ft_print_stack(stack_a);
	ft_printf("stack_b:\n");
	ft_print_stack(stack_b);
	
	ft_push_b(&stack_b, &stack_a);
	ft_printf("stack_a:\n");
	ft_print_stack(stack_a);
	ft_printf("stack_b:\n");
	ft_print_stack(stack_b);

	ft_push_a(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	ft_print_stack(stack_a);
	ft_printf("stack_b:\n");
	ft_print_stack(stack_b);*/

	(void)stack_b;
	return (0);
}