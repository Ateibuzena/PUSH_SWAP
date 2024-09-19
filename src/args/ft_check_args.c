#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"


char	*ft_join_args(int argc, char *argv[])
{
	char	*join;
	//char	*temp;
	int		i;
	
	i = 1;
	join = argv[i];
	i++;
	while (i < argc)
	{
		//temp = join;
		join = ft_strjoin((char const *)join, (char const *)argv[i]);
		//free(temp);
		i++;
	}
	return (join);
}

int	ft_isduplicate(char **split, int pos_f)
{
	int	i;

	i = 0;
	if (pos_f != 0)
	{
		while (i < pos_f)
		{
			if (!ft_strncmp(split[i],
				split[pos_f],
				ft_max(ft_strlen(split[i]),
				ft_strlen(split[pos_f]))))
				return (1);
			i++;
		}
	}
	return (0);
}

char	**ft_check_args(int argc, char *argv[])
{
	char	*join;
	char	**split;
	int		i;

	i = 0;
	join = ft_join_args(argc, argv);
	split = ft_split((char const *)join, ' ');
	while (split[i])
	{
		if (!ft_atoi(split[i]) || ft_isduplicate(split, i))
		{
			free(split);
			return (NULL);
		}
		i++;
	}
	return (split);
}
