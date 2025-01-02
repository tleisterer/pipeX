/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:04:38 by tleister          #+#    #+#             */
/*   Updated: 2024/10/25 17:35:22 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_bonus.h"
#include <stdio.h>

static int	writesign(t_flags flags, int minus)
{
	if (minus)
		return (write(1, "-", 1));
	else if (flags.plus == 1)
		return (write(1, "+", 1));
	else
		return (write(1, " ", 1));
}

static int	recursion(long long nb, int i)
{
	int	temp;

	if (nb != 0)
	{
		i = recursion(nb / 10, i + 1);
		temp = nb % 10 + 48;
		write(1, &temp, 1);
	}
	return (i);
}

static int	check(t_flags flags, long long n, int len)
{
	int	i;

	i = 0;
	i += checkprecision(flags, countsize(n, "0123456789"));
	if (flags.minus == 0 && flags.zero == 1)
		i += ft_checkwidth(flags, len);
	if (n == 0 && flags.precision != 0)
		i += write(1, "0", 1);
	return (i);
}

static int	setlen(long long n, int sign, t_flags flags)
{
	int	len;

	len = countsize(n, "0123456789") + sign;
	if (len <= flags.precision || (n == 0 && flags.precision == 0))
		len = flags.precision + sign;
	return (len);
}

int	ft_putnbr_flag(long long n, t_flags flags)
{
	int	i;
	int	sign;
	int	minus;
	int	len;

	minus = 0;
	sign = 0;
	i = 0;
	if (n < 0 || flags.plus == 1 || flags.space == 1)
		sign = 1;
	if (n < 0)
	{
		n *= -1;
		minus = 1;
	}
	len = setlen(n, sign, flags);
	if (flags.minus == 0 && flags.zero == 0)
		i += ft_writewidth(flags, len);
	if (sign == 1)
		i += writesign(flags, minus);
	i += check(flags, n, len);
	i = recursion(n, i);
	if (flags.minus == 1)
		i += ft_writewidth(flags, len);
	return (i);
}
