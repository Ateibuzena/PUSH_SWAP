/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:45:56 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/23 18:46:56 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushlibft.h"

char	*ft_join_args(int argc, char *argv[])
{
	char	*join;
	char	*temp;
	int		i;

	i = 1;
	join = ft_strdup(argv[i]);
	i++;
	while (i < argc)
	{
		temp = join;
		join = ft_join((char const *)join, (char const *)argv[i]);
		free(temp);
		i++;
	}
	return (join);
}

int	ft_duplicate_args(char **split, int pos_f)
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
	int		n;

	i = 0;
	join = ft_join_args(argc, argv);
	split = ft_split((char const *)join, ' ');
	free(join);
	while (split[i])
	{
		n = ft_atoi(split[i]);
		if ((!ft_isdigit(split[i][0]) && split[i][0] != '-')
			|| (split[i][0] != '0' && !n) || ft_duplicate_args(split, i))
		{
			ft_free_split(split);
			return (NULL);
		}
		i++;
	}
	return (split);
}
