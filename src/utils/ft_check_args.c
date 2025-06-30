/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:45:56 by azubieta          #+#    #+#             */
/*   Updated: 2025/06/30 23:29:08 by azubieta         ###   ########.fr       */
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
	int num_posf;
	int num_i;

	num_posf = ft_atoi(split[pos_f]);
	i = 0;
	while (i < pos_f)
	{
		num_i = ft_atoi(split[i]);
		if (num_i == num_posf)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_range(const char *str)
{
	long	val;
	char	*endptr;

	val = ft_strtol(str, &endptr, 10);
	if (*endptr != '\0')
		return (0);
	if ((val > INT_MAX) || (val < INT_MIN))
		return (0);
	return (1);
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
			|| (split[i][0] != '0' && !n)
			|| !ft_strisnumber(split[i])
			|| !ft_check_range(split[i])
			|| ft_duplicate_args(split, i))
		{
			ft_free_split(split);
			return (NULL);
		}
		i++;
	}
	return (split);
}
