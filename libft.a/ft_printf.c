/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:08:29 by tleister          #+#    #+#             */
/*   Updated: 2024/12/06 12:45:16 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		counter;
	t_flags	flags;
	va_list	ap;

	counter = 0;
	va_start(ap, format);
	i = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++;
			i += checkflags(&flags, ap, format + i);
			count = checkarg(format[i], ap, flags);
			if (count == -1)
				return (va_end(ap), -1);
			counter += count;
		}
		else
			counter += write(1, &format[i], 1);
		i++;
	}
	return (va_end(ap), counter);
}
