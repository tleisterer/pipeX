/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:30:50 by tleister          #+#    #+#             */
/*   Updated: 2025/01/02 13:32:19 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getwordamount(const char *s, char c)
{
	int	newword;
	int	counter;

	newword = 0;
	counter = 0;
	if (s != NULL)
		while (*s != 0)
		{
			if (*s != c)
				newword = 1;
			if (*s == c && newword == 1)
			{
				newword = 0;
				counter++;
			}
			s++;
		}
	return (counter + newword);
}

static char	*getword(char const *s, char c, int index)
{
	char	*str;
	int		counter;

	counter = 0;
	while (*s == c)
		s++;
	while (index != 0)
	{
		s++;
		if (*s != c && *(s - 1) == c)
			index--;
	}
	while (s[counter] != '\0' && s[counter] != c)
		counter++;
	str = malloc((counter + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	counter = 0;
	while (s[counter] != '\0' && s[counter] != c)
	{
		str[counter] = s[counter];
		counter++;
	}
	str[counter] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**res;
	int		wordamount;

	wordamount = getwordamount(s, c);
	wordcount = 0;
	res = malloc(sizeof(char *) * (wordamount + 1));
	if (res == NULL)
		return (NULL);
	while (wordcount < wordamount)
	{
		res[wordcount] = getword(s, c, wordcount);
		if (res[wordcount] == NULL)
		{
			while (wordcount >= 0)
			{
				free(res[wordcount]);
				wordcount--;
			}
			return (free(res), NULL);
		}
		wordcount++;
	}
	res[wordcount] = 0;
	return (res);
}
