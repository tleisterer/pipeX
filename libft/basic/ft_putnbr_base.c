/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:44:21 by tleister          #+#    #+#             */
/*   Updated: 2024/10/23 15:55:03 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	recursion(long long nb, char *base, size_t len, int i)
{
	if (nb != 0)
	{
		i = recursion(nb / len, base, len, i + 1);
		write(1, &base[nb % len], 1);
	}
	return (i);
}

int	ft_putnbr_base(long long nb, char *base)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(base);
	if (nb == 0)
	{
		write(1, &base[0], 1);
		i++;
	}
	return (recursion(nb, base, len, i));
}
