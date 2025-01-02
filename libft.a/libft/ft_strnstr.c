/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:47:11 by tleister          #+#    #+#             */
/*   Updated: 2024/10/18 10:58:59 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;
	size_t	i;

	nlen = 0;
	i = 0;
	while (needle[nlen])
		nlen++;
	if (nlen == 0)
		return ((char *)haystack);
	ft_strncmp(haystack, needle, nlen);
	while (i + nlen <= len)
	{
		if (*haystack == 0)
			return (0);
		if (ft_strncmp(haystack, needle, nlen) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}
