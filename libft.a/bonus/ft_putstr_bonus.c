/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:11:15 by tleister          #+#    #+#             */
/*   Updated: 2024/10/25 13:57:24 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_bonus.h"

static int	ft_putlstr(char *s, int len)
{
	int	i;

	i = 0;
	while (*s && (len - i > 0 || len < 0))
	{
		i += write(1, s, 1);
		s++;
	}
	return (i);
}

static int	writenull(int maxlen)
{
	char	*temp;
	int		i;

	i = 0;
	temp = "(null)";
	while (temp[i] && (i < maxlen || maxlen < 0))
	{
		write(1, &temp[i], 1);
		i++;
	}
	return (i);
}

int	ft_putstr_flag(char *s, t_flags flags)
{
	int	i;
	int	maxlen;
	int	strlen;

	if (s == 0)
		strlen = 6;
	else
		strlen = ft_strlen(s);
	i = 0;
	maxlen = flags.precision;
	if (flags.minus == 0)
		i += ft_checkwidth(flags, strlen);
	if (s == 0)
		i += writenull(maxlen);
	else
		i += ft_putlstr(s, maxlen);
	if (flags.minus == 1)
		i += ft_checkwidth(flags, strlen);
	return (i);
}
