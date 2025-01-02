/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:42:50 by tleister          #+#    #+#             */
/*   Updated: 2024/10/17 12:31:29 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strncpy(char *dst, const char *src, int len)
{
	int	counter;

	counter = 0;
	while (counter < len)
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = 0;
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		lnb;
	int		rnb;
	char	*str;

	i = 0;
	while (isinset(s1[i], set) == 1)
		i++;
	lnb = i;
	i = ft_strlen(s1) - 1;
	while (isinset(s1[i], set) == 1)
		i--;
	rnb = i;
	if (rnb >= lnb)
		str = malloc(rnb - lnb + 2);
	else
		return (ft_calloc(1, 1));
	if (str == 0)
		return (0);
	return (ft_strncpy(str, s1 + lnb, rnb - lnb + 1));
}
