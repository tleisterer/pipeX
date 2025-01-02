/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:11:15 by tleister          #+#    #+#             */
/*   Updated: 2024/10/23 20:01:54 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_putstr_count(char *s)
{
	if (s == 0)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}
