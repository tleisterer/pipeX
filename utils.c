/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:11:15 by tleister          #+#    #+#             */
/*   Updated: 2025/01/02 11:44:40 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	int	fd;

	fd = open("error", O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDERR_FILENO);
	close(fd);
	perror(str);
	exit(EXIT_FAILURE);
}
