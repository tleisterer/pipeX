/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:43:39 by tleister          #+#    #+#             */
/*   Updated: 2025/01/02 10:34:08 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_getline(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || !buffer[0])
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

static char	*ft_next(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0)
		return (ft_free(&buffer));
	i++;
	temp = malloc(ft_strlen(buffer) - i + 1);
	if (!temp)
		return (0);
	j = 0;
	while (buffer[i + j])
	{
		temp[j] = buffer[i + j];
		j++;
	}
	temp[j] = 0;
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*temp;
	int			byte_read;
	static char	*buffer[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	byte_read = 1;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	while (!(ft_strchr(buffer[fd], '\n')) && byte_read > 0)
	{
		byte_read = read(fd, temp, BUFFER_SIZE);
		if (byte_read == -1)
			return (ft_free(&buffer[fd]), ft_free(&temp));
		temp[byte_read] = 0;
		buffer[fd] = ft_gnl_strjoin(buffer[fd], temp);
		if (!buffer[fd])
			return (ft_free(&temp));
	}
	free(temp);
	temp = ft_getline(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (temp);
}
