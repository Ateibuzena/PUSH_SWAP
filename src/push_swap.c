#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**split;

	stack_a = NULL;
	stack_b = NULL;
	if (argc != 2)
	{
		if (ft_check_arguments(argc, argv))
		{
			ft_init_value(&stack_a, argc, argv);
			/*ft_printf("init_value\n");
			ft_print_stack(stack_a);*/
		}
	}
	else
	{
		if (ft_one_argument(argv))
		{
			split = ft_one_argument(argv);
			ft_init_value(&stack_a, argc, split);
			/*ft_printf("init_value\n");
			ft_print_stack(stack_a);*/
		}
	}
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