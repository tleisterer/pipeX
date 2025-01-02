/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:51:57 by tleister          #+#    #+#             */
/*   Updated: 2024/11/05 11:37:20 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	num;

	num = 0;
	while (*str)
	{
		str++;
		num++;
	}
	return (num);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	temp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!temp)
		return (0);
	i = -1;
	while (s1 && s1[++i])
		temp[i] = s1[i];
	j = -1;
	while (s2 && s2[++j])
		temp[i + j] = s2[j];
	temp[i + j] = '\0';
	free(s1);
	return (temp);
}

char	*ft_strchr(char *s, int c)
{
	int	counter;

	if (!s)
		return (0);
	counter = 0;
	while (s[counter])
	{
		if (s[counter] == (char)c)
			return (s + counter);
		counter++;
	}
	if (s[counter] == (char)c)
		return (s + counter);
	return (0);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = 0;
	return (0);
}
