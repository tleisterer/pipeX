/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:18:22 by tleister          #+#    #+#             */
/*   Updated: 2024/10/25 12:49:08 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/ft_printf.h"

int	isflag(char c)
{
	int	i;

	i = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	initflags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->hashtag = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->usage = 1;
}

void	setplus(t_flags *flags)
{
	flags->plus = 1;
	flags->space = 0;
}

void	setminus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

void	setsignflagsback(t_flags *flags)
{
	flags->space = 0;
	flags->plus = 0;
}
