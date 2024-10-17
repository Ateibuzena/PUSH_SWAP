/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:46:17 by azubieta          #+#    #+#             */
/*   Updated: 2024/10/12 15:16:41 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/azubieta/sgoinfre/azubieta/PUSH_SWAP/pushlibft.h"

char	*ft_join(char const *s1, char const *s2)
{
	char		*join;
	t_size		i;
	t_size		n;

	n = -1;
	i = -1;
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!join)
		return (NULL);
	if (!s1 && !s2)
	{
		free(join);
		return (NULL);
	}
	while (++i < ft_strlen(s1))
		join[i] = s1[i];
	join[i++] = ' ';
	while (++n < ft_strlen(s2))
		join[i++] = s2[n];
	join[i] = '\0';
	return (join);
}
