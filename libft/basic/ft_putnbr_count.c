/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:04:38 by tleister          #+#    #+#             */
/*   Updated: 2024/10/23 09:56:30 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

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

int	ft_putnbr_count(long long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		i++;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		i++;
	}
	return (recursion(n, i));
}
