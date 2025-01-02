/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:20:25 by tleister          #+#    #+#             */
/*   Updated: 2024/10/25 12:46:08 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_bonus.h"

int	ft_putchar_flag(char c, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.minus == 0)
		i += ft_writewidth(flags, 1);
	i += write(1, &c, 1);
	if (flags.minus == 1)
		i += ft_writewidth(flags, 1);
	return (i);
}
