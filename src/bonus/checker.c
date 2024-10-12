#include "/mnt/c/Users/enaat/Documents/Repositorios/42/push_swap/pushlibft.h"
#include "/mnt/c/Users/enaat/Documents/Repositorios/42/libft/libft.h"

typedef struct s_pushswap
{
	char	*key;
	void	(*ft_ft)();
}	t_PushSwap;

static void    ft_init_pushswap_structure(t_PushSwap **data)
{
    data[0]->key = "ra";
    data[1]->key = "rb";
    data[2]->key = "rr";
    data[3]->key = "rra";
    data[4]->key = "rrb";
    data[5]->key = "rrr";
    data[6]->key = "pa";
    data[7]->key = "pb";
    data[8]->key = "sa";
    data[9]->key = "sb";
    data[0]->ft_ft = ft_rotate;
    data[1]->ft_ft = ft_rotate;
    data[2]->ft_ft = ft_rotate;
    data[3]->ft_ft = ft_reverse;
    data[4]->ft_ft = ft_reverse;
    data[5]->ft_ft = ft_reverse;
    data[6]->ft_ft = ft_push;
    data[7]->ft_ft = ft_push;
    data[8]->ft_ft = ft_swap;
    data[9]->ft_ft = ft_swap;
}

void    ft_execute_bonus_moves(char **buffer, int   index, t_stack **stack_a, t_stack **stack_b)
{
    int         i;
    int         count;
    t_PushSwap  *data;

    i = 0;
    ft_init_pushswap_structure(&data);
    while (i < index - 1)
    {
        count = 0;
        while (count < 10)
        {
            if (!ft_strncmp(buffer[i], data[count].key, ft_max(ft_strlen(buffer[i]), ft_strlen(data[count].key))))
            {
                if (buffer[i][1] == 'a')
                    data[count].ft_ft(stack_a);
                else if  (buffer[i][1] == 'b')
                    data[count].ft_ft(stack_b);
                else if(!buffer[i][2] && buffer[i][1] == 'r')
                {
                    data[count].ft_ft(stack_a);
                    data[count].ft_ft(stack_b);
                }
                else if(buffer[i][2] && buffer[i][2] == 'r')
                {
                    data[count].ft_ft(stack_a);
                    data[count].ft_ft(stack_b);
                }
            }
            count++;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    t_stack		*stack_a;
	t_stack		*stack_b;
	char		**split;
    char        *buffer[2147483647];
    int         index;
    char        *line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	split = ft_check_args(argc, argv);
	if (!split)
		return (ft_printf("Error\n"), 1);
	(ft_init_value(&stack_a, split), ft_free_split(split));
    index = 0;
    while (index < 2147483647)
    {
        line = get_next_line(0);
        if (line == NULL)
            break ;
        buffer[index] = line;
        index++;
    }
    ft_execute_bonus_moves(buffer, index, &stack_a, &stack_b);
    ft_free_split(buffer);
}