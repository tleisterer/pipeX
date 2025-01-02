/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:58:43 by tleister          #+#    #+#             */
/*   Updated: 2024/11/15 12:59:27 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

# define FLAGS "+- #0"
# define UHEX "0123456789ABCDEF"
# define LHEX "0123456789abcdef"

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	hashtag;
	int	space;
	int	plus;
	int	precision;
	int	width;
	int	usage;
}		t_flags;

int		ft_printf(const char *format, ...);
int		checkflags(t_flags *flags, va_list ap, const char *input);
void	initflags(t_flags *flags);
void	setplus(t_flags *flags);
void	setminus(t_flags *flags);
int		isflag(char c);
void	setsignflagsback(t_flags *flags);

int		checkprecision(t_flags flags, int nblen);
int		ft_checkwidth(t_flags flags, int print);
int		ft_writewidth(t_flags flags, int check);

int		ft_putstr_flag(char *s, t_flags flags);
int		ft_putptr_flag(unsigned long long nb, char *base, t_flags flags);
int		ft_putnbr_flag(long long n, t_flags flags);
int		ft_putnbr_base_flag(long long nb, char *base, t_flags flags);
int		ft_putchar_flag(char c, t_flags flags);
int		countsize(unsigned long long nb, char *base);

// void	printflags(t_flags *flags);
int		ft_putchar(char chr, int nb);
int		ft_putstr(char *chr, int nb);

#endif
