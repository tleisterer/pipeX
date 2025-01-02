/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:38:40 by tleister          #+#    #+#             */
/*   Updated: 2024/10/11 13:25:25 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr;
	const unsigned char	*ptr2;

	ptr = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 1 && *ptr == *ptr2)
	{
		ptr++;
		ptr2++;
		n--;
	}
	return (*ptr - *ptr2);
}
