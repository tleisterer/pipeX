/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:06:14 by tleister          #+#    #+#             */
/*   Updated: 2024/10/15 17:03:19 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	counter;

	counter = 0;
	while (src[counter] != 0 && counter < len)
	{
		dst[counter] = src[counter];
		counter++;
	}
	while (counter < len)
	{
		dst[counter] = 0;
		counter++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = 0;
	while (src[srcsize] != 0)
		srcsize++;
	if (srcsize < dstsize)
		ft_strncpy(dst, src, srcsize + 1);
	else if (dstsize != 0)
	{
		ft_strncpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (srcsize);
}
