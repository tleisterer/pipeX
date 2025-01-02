/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:11:41 by tleister          #+#    #+#             */
/*   Updated: 2024/10/17 16:36:20 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (s[counter] != 0)
	{
		if (s[counter] == (char)c)
			return ((char *)s + counter);
		counter++;
	}
	if (s[counter] == (char)c)
		return ((char *)s + counter);
	return (0);
}
