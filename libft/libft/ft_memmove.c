/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:36:04 by tleister          #+#    #+#             */
/*   Updated: 2024/10/17 13:45:15 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	if (dest == 0 && src == 0)
		return (0);
	if (ptr2 < ptr)
	{
		ft_memcpy(dest, src, len);
	}
	else
	{
		while (len > 0)
		{
			*ptr = *ptr2;
			ptr++;
			ptr2++;
			len--;
		}
	}
	return (dest);
}
