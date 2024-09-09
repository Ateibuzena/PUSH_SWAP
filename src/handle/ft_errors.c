#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

int	ft_argc_error(void)
{
	ft_printf("This program need to be execute:\n");
	ft_printf("- With one argument minimun\n");
	ft_printf("- The arguments of this program must be interger numbers\n");
	ft_printf("- The arguments of this program can't be duplilcated\n");
	return (0);
}

int	ft_argv_error(void)
{
	ft_printf("The arguments of this program must be interger numbers\n");
	return (0);
}

int	ft_argv_duplicate(void)
{
	ft_printf("The arguments of this program can't be duplilcated\n");
	return (0);	
}