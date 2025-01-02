/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:21:54 by tleister          #+#    #+#             */
/*   Updated: 2024/10/15 19:16:02 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	skipspace(const char *c)
{
	int	i;

	i = 0;
	while (c[i] == ' ' || c[i] == '\t' || c[i] == '\n' || c[i] == '\v'
		|| c[i] == '\f' || c[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	counter;
	int	number;
	int	minus;

	minus = 1;
	counter = 0;
	number = 0;
	if (str[counter] != 0)
	{
		counter = skipspace(str);
		if (str[counter] == '-' || str[counter] == '+')
		{
			if (str[counter] == '-')
				minus *= -1;
			counter++;
		}
		while (str[counter] >= '0' && str[counter] <= '9')
		{
			number = number * 10 + (int)str[counter] - 48;
			counter++;
		}
	}
	return (number * minus);
}
