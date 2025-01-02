/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:34:27 by tleister          #+#    #+#             */
/*   Updated: 2024/10/25 11:44:01 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/ft_printf.h"

static int	checkstar(const char *input, int *flag, va_list ap)
{
	int	i;

	i = 0;
	*flag = 0;
	if (*input == '*')
	{
		*flag = va_arg(ap, int);
		i++;
	}
	else if (ft_isdigit(*input))
	{
		*flag = ft_atoi(input);
		while (ft_isdigit(input[i]))
			i++;
	}
	return (i);
}

int	checkflags(t_flags *flags, va_list ap, const char *input)
{
	int	i;

	i = 0;
	initflags(flags);
	while (isflag(input[i]))
	{
		if (input[i] == '+')
			setplus(flags);
		else if (input[i] == ' ' && flags->plus == 0)
			flags->space = 1;
		if (input[i] == '-')
			setminus(flags);
		else if (input[i] == '0' && flags->minus == 0)
			flags->zero = 1;
		if (input[i] == '#')
			flags->hashtag = 1;
		i++;
	}
	i += checkstar(input + i, &flags->width, ap);
	if (input[i] == '.')
	{
		i += checkstar(input + i + 1, &flags->precision, ap) + 1;
		flags->zero = 0;
	}
	return (i);
}
