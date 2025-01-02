/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:25:38 by tleister          #+#    #+#             */
/*   Updated: 2024/10/14 12:40:56 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while (s1[counter] == s2[counter] && counter < n - 1 && s1[counter] != 0)
		counter++;
	if (n == 0)
		return (0);
	return ((unsigned char) s1[counter] - (unsigned char) s2[counter]);
}
