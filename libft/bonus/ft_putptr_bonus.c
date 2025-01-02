/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:26:54 by tleister          #+#    #+#             */
/*   Updated: 2024/10/25 17:38:01 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_bonus.h"

static int	recursion(unsigned long long nb, char *base, size_t len, int i)
{
	if (nb != 0)
	{
		i = recursion(nb / len, base, len, i + 1);
		write(1, &base[nb % len], 1);
	}
	return (i);
}

int	ft_putptr_flag(unsigned long long nb, char *base, t_flags flags)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(base);
	if (flags.minus == 0)
		i += ft_checkwidth(flags, countsize(nb, base) + 2);
	i += write(1, "0x", 2);
	if (nb == 0)
	{
		write(1, &base[0], 1);
		i++;
	}
	i = recursion(nb, base, len, i);
	if (flags.minus == 1)
		i += ft_checkwidth(flags, countsize(nb, base) + 2);
	return (i);
}
