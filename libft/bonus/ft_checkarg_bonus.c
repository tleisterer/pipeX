/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:23:10 by tleister          #+#    #+#             */
/*   Updated: 2024/11/13 11:50:14 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_bonus.h"

int	checkarg(const char c, va_list ap, t_flags flags)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_flag(va_arg(ap, int), flags));
	if (c == 's')
		return (ft_putstr_flag(va_arg(ap, char *), flags));
	if (c == '%')
		return (ft_putchar_flag('%', flags));
	if (c == 'x')
		return (ft_putnbr_base_flag(va_arg(ap, unsigned int),
				LHEX, flags));
	if (c == 'X')
		return (ft_putnbr_base_flag(va_arg(ap, unsigned int),
				UHEX, flags));
	if (c == 'u')
		return (ft_putnbr_flag(va_arg(ap, unsigned int), flags));
	if (c == 'c')
		return (ft_putchar_flag(va_arg(ap, int), flags));
	if (c == 'p')
		return (ft_putptr_flag((unsigned long long)va_arg(ap, void *),
				LHEX, flags));
	return (0);
}
