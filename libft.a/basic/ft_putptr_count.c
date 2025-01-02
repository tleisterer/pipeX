/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:26:54 by tleister          #+#    #+#             */
/*   Updated: 2024/11/13 11:51:13 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	recursion(unsigned long long nb, char *base, size_t len, int i)
{
	if (nb != 0)
	{
		i = recursion(nb / len, base, len, i + 1);
		write(1, &base[nb % len], 1);
	}
	return (i);
}

int	ft_putptr_count(unsigned long long nb, char *base)
{
	size_t	len;
	int		i;

	i = write(1, "0x", 2);
	len = ft_strlen(base);
	if (nb == 0)
	{
		write(1, &base[0], 1);
		i++;
	}
	return (recursion(nb, base, len, i));
}
