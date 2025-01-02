/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:44:21 by tleister          #+#    #+#             */
/*   Updated: 2024/11/07 10:52:18 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_bonus.h"
#include <stdio.h>

static int	recursion(long long nb, char *base, size_t len, int i)
{
	if (nb != 0)
	{
		i = recursion(nb / len, base, len, i + 1);
		write(1, &base[nb % len], 1);
	}
	return (i);
}

static int	checkhashtag(int *hashtag, char c, long long nb)
{
	char	temp;

	if (*hashtag == 1 && nb != 0)
	{
		temp = 'x' - 'a' + c;
		write(1, "0", 1);
		write(1, &temp, 1);
		return (2);
	}
	return (0);
}

int	ft_putnbr_base_flag(long long nb, char *base, t_flags flags)
{
	size_t	len;
	int		i;
	int		nblen;

	i = 0;
	nblen = countsize(nb, base);
	len = ft_strlen(base);
	if (nblen < flags.precision || (nb == 0 && flags.precision == 0))
		nblen = flags.precision;
	if (nb == 0)
		flags.hashtag = 0;
	if (flags.minus == 0 && flags.zero == 0)
		i += ft_writewidth(flags, nblen);
	i += checkhashtag(&flags.hashtag, base[10], nb);
	if (flags.minus == 0 && flags.zero == 1)
		i += ft_writewidth(flags, nblen);
	i += checkprecision(flags, countsize(nb, base));
	if (nb == 0 && flags.precision != 0)
		i += write(1, &base[0], 1);
	i = recursion(nb, base, len, i);
	if (flags.minus == 1)
		i += ft_writewidth(flags, nblen);
	return (i);
}
