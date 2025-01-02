/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:03:54 by tleister          #+#    #+#             */
/*   Updated: 2024/10/17 13:35:56 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*substr;

	i = 0;
	s_len = start;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	while (s[s_len] != 0)
		s_len++;
	s_len -= start;
	if (s_len < len)
		substr = malloc(s_len + 1);
	else
	{
		substr = malloc(len + 1);
		s_len = len;
	}
	if (substr == 0)
		return (0);
	ft_strlcpy(substr, s + start, s_len + 1);
	return (substr);
}
