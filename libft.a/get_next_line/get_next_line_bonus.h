/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:42:34 by tleister          #+#    #+#             */
/*   Updated: 2025/01/02 10:36:36 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

/* ----utils---- */

char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_free(char **str);

#endif