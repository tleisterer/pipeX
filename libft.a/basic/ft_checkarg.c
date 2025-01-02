/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:23:10 by tleister          #+#    #+#             */
/*   Updated: 2024/11/13 11:51:06 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	checkarg(const char c, va_list ap, t_flags flags)
{
	flags.usage = 0;
	if (c == 'd' || c == 'i')
		return (ft_putnbr_count(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr_count(va_arg(ap, char *)));
	if (c == '%')
		return (ft_putchar_count('%'));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(ap, unsigned int), LHEX));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(ap, unsigned int), UHEX));
	if (c == 'u')
		return (ft_putnbr_count(va_arg(ap, unsigned int)));
	if (c == 'c')
		return (ft_putchar_count(va_arg(ap, int)));
	if (c == 'p')
		return (ft_putptr_count((unsigned long long)va_arg(ap, void *), LHEX));
	return (-1);
}
