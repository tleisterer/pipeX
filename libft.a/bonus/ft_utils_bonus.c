/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:37:50 by tleister          #+#    #+#             */
/*   Updated: 2024/10/25 17:38:06 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_bonus.h"

int	ft_writewidth(t_flags flags, int check)
{
	int	i;
	int	minlen;

	i = 0;
	if (flags.hashtag == 1)
		check += 2;
	minlen = flags.width;
	if (flags.zero == 1)
		while (minlen - i - check > 0)
			i += write(1, "0", 1);
	else
		while (minlen - i - check > 0)
			i += write(1, " ", 1);
	return (i);
}

int	ft_checkwidth(t_flags flags, int printlen)
{
	int	maxlen;

	maxlen = flags.precision;
	if (flags.hashtag == 1)
		printlen += 2;
	if (printlen < maxlen || maxlen < 0)
		return (ft_writewidth(flags, printlen));
	else
		return (ft_writewidth(flags, maxlen));
}

int	checkprecision(t_flags flags, int nblen)
{
	int	i;

	i = 0;
	while (nblen + i < flags.precision)
		i += write(1, "0", 1);
	return (i);
}

int	countsize(unsigned long long nb, char *base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= ft_strlen(base);
		i++;
	}
	return (i);
}
