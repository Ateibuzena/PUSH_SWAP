#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

void ft_free_split(char **split)
{
    int i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
