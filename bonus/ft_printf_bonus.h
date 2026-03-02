/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:23:25 by jopajuel          #+#    #+#             */
/*   Updated: 2026/03/02 13:06:36 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int	hash;
	int	point;
	int	minus;
	int	plus;
	int	num;
	int	num_dot;
	int	zero;
	int	iter;
	int	space;
}	t_flags;

typedef struct s_d
{
	long	nb;
	char	sign;
	int		num_len;
	int		zeros;
	int		padding;
}	t_d;

typedef struct s_u
{
	unsigned int	nb;
	int				num_len;
	int				zeros;
	int				padding;
}	t_u;

typedef struct s_x
{
	unsigned int	nb;
	int				num_len;
	int				zeros;
	int				padding;
	int				prefix;
}	t_x;

typedef struct s_p
{
	unsigned long	nb;
	int				num_len;
	int				zeros;
	int				padding;
}	t_p;

int		ft_printf(char	const *str, ...);
int		ft_detec_plus(char const *str, int *i, va_list list, t_flags *flags);
void	ft_detec_args(char const **str, int *i, va_list list, t_flags *flags);
void	ft_detec_flags(char const *str, t_flags *flags);

int		ft_printstring(va_list list, int *i, t_flags *flags);
int		ft_printchar(va_list list, int *i, t_flags *flags);
int		ft_printpointer(va_list list, int *i, t_flags *flags);
int		ft_printinteger(va_list list, int *len, t_flags *flags);
int		ft_printunsigned(va_list list, int *len, t_flags *flags);
int		ft_printhexa(va_list ap, char upper, int *len, t_flags *f);

void	ft_init_struct(t_flags *flags);
void	print_padding(int n, char c, int *len);
void	ft_putchar_len(char c, int *len);
void	ft_putnbr_unsigned_len(unsigned long n, int *len);
int		ft_numlen_base(unsigned long n, int base);
int		ft_numlen_base_int(unsigned int n, int base);
void	ft_putnbr_base_len(unsigned long n, char *base, int *len);
void	ft_case_null(t_flags *f, int print_len);
#endif