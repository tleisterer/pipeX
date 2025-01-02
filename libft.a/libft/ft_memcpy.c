/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:14:55 by tleister          #+#    #+#             */
/*   Updated: 2024/10/17 13:40:51 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (dest == 0 && src == 0)
		return (0);
	ptr = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	while (n > 0)
	{
		ptr[n - 1] = ptr2[n - 1];
		n--;
	}
	return (dest);
}
