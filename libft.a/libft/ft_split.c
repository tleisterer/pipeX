/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:38:53 by tleister          #+#    #+#             */
/*   Updated: 2024/10/21 12:23:00 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i] != 0)
	{
		if (s[i] == c && i > 0)
			if (s[i - 1] != c)
				counter++;
		i++;
	}
	if (s[0] == 0 || s[i - 1] == c)
		return (counter);
	return (counter + 1);
}

static void	wordlengt(const char *s, char c, int *numbers)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
			numbers[j]++;
		else if (i > 0)
		{
			if (s[i - 1] != c)
				j++;
		}
		i++;
	}
}

static char	**copysplit(const char *s, char c, char **dstr)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	j = 0;
	while ((size_t)k < ft_strlen(s))
	{
		while (s[k] != c && s[k] != 0)
			dstr[i][j++] = s[k++];
		if (((s[k] == c || s[k] == 0) && k > 0))
		{
			if (s[k - 1] != c)
			{
				dstr[i++][j] = 0;
				j = 0;
			}
		}
		k++;
	}
	return (dstr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**dstr;
	int		*numbers;

	dstr = malloc((countwords(s, c) + 1) * sizeof(char *));
	numbers = ft_calloc(countwords(s, c), sizeof(int));
	if (dstr == 0 || numbers == 0)
		return (0);
	wordlengt(s, c, numbers);
	i = 0;
	j = 0;
	while (i < countwords(s, c))
	{
		dstr[i] = malloc(numbers[i] + 1);
		if (dstr[i] == 0)
			return (0);
		i++;
	}
	dstr[i] = 0;
	free(numbers);
	return (copysplit(s, c, dstr));
}
