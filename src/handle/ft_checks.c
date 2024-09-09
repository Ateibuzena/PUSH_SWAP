#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

char	**ft_one_argument(char *argv[])
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(argv[1], ' ');
	if (!split || !split[0])
	{
		free(split);
		ft_argv_error();
		return (NULL);
	}
		i = 0;
	while (split[i])
	{
		if (!ft_atoi(split[i]))
		{
			free(split);
			ft_argv_error();
			return (NULL);
		}
		j = i + 1;
		while (split[j])
		{
			if (ft_strncmp(split[i], split[j], ft_strlen(split[i])) == 0)
			{
				free(split);
				ft_argv_duplicate();
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (split);
}

int	ft_check_arguments(int argc, char *argv[])
{
	int		i;
	int		j;

	if (argc < 2)
		return (ft_argc_error());
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]))
			return (ft_argv_error());
		j = i + 1;
		while (j < argc)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				return (ft_argv_duplicate());
			j++;
		}
		i++;
	}
	return (1);
}
