/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleister <tleister@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:38:46 by tleister          #+#    #+#             */
/*   Updated: 2024/11/15 12:59:33 by tleister         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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

int		checkarg(const char c, va_list ap, t_flags flags);
int		ft_putnbr_base(long long nb, char *base);
int		ft_putnbr_count(long long n);
int		ft_putstr_count(char *s);
int		ft_putchar_count(char c);
int		ft_putptr_count(unsigned long long nb, char *base);

// void	printflags(t_flags *flags);
int	fd_putchar(char chr, int nb);
int	ft_putstr(char *chr, int nb);
#endif
