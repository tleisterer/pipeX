/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:18:07 by tleister          #+#    #+#             */
/*   Updated: 2024/10/17 16:49:06 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = ft_strlen(s);
	while (counter >= 0)
	{
		if (s[counter] == (char)c)
			return ((char *)s + counter);
		counter--;
	}
	return (0);
}
