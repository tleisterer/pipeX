/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:01:17 by tleister          #+#    #+#             */
/*   Updated: 2024/10/17 12:24:27 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*getnbr(int n, char *s)
{
	if (n != 0)
	{
		s = getnbr(n / 10, s);
		if (n < 0)
			*s = n % 10 * -1 + 48;
		else
			*s = n % 10 + 48;
		s++;
	}
	return (s);
}

static char	*zero(void)
{
	char	*s;

	s = ft_calloc(2, 1);
	if (s == 0)
		return (0);
	s[0] = '0';
	return (s);
}

static int	getnbrlength(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		minus;

	minus = 0;
	if (n == 0)
		return (zero());
	if (n < 0)
		minus = 1;
	str = malloc(getnbrlength(n) + 1 + minus);
	if (str == 0)
		return (0);
	if (minus == 1)
		*str = '-';
	getnbr(n, str + minus);
	str[getnbrlength(n) + minus] = 0;
	return (str);
}
