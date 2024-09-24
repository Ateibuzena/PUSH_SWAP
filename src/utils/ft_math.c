/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:41:43 by azubieta          #+#    #+#             */
/*   Updated: 2024/09/24 13:41:50 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}
