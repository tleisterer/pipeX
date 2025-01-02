/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:11:15 by tleister          #+#    #+#             */
/*   Updated: 2025/01/02 16:20:42 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	int	fd;

	fd = open("error", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (dup2(fd, STDERR_FILENO) == -1)
		ft_error("error: dup2");
	if (close(fd) == -1)
		ft_error("error: close");
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_split(char **input)
{
	int	counter;

	counter = 0;
	while (input[counter] != NULL)
	{
		free(input[counter]);
		counter++;
	}
	free(input);
}
