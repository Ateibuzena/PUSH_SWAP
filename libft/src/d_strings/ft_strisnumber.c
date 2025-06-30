/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:04:29 by azubieta          #+#    #+#             */
/*   Updated: 2025/06/30 23:04:49 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strisnumber(char *str)
{
	int i = 0;

	if (str[0] == '-' && str[1] != '\0')
		i = 1; // permite el signo negativo solo en la primera posición

	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0); // hay un carácter que no es dígito
		i++;
	}
	return (1);
}
