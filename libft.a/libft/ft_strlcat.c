/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:38:08 by tleister          #+#    #+#             */
/*   Updated: 2024/10/15 18:54:57 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	i;
	int		j;

	counter = 0;
	j = 0;
	while (dst[counter])
		counter++;
	if (dstsize < counter)
		j = ft_strlen(dst) - dstsize;
	i = counter;
	while (counter + 1 < dstsize && src[counter - i] != 0)
	{
		dst[counter] = src[counter - i];
		counter++;
	}
	dst[counter] = 0;
	while (src[counter - i])
		counter++;
	return (counter - j);
}
