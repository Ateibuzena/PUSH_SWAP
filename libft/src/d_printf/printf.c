/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:58:41 by azubieta          #+#    #+#             */
/*   Updated: 2025/06/17 19:00:07 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	*handler;
	int			i;
	int			count;

	i = 0;
	count = 0;
	va_start(args, format);
	if (!ft_init_handlers(&handler))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			count += ft_call_handler(handler, format[i++], args);
		}
		else
			count += write(1, &format[i++], 1);
	}
	ft_free_handlers(handler);
	va_end(args);
	return (count);
}
