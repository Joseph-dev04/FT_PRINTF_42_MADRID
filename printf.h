/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:23:25 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/30 15:14:01 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FT_PRINTF_H
# define	FT_PRINTF_H
#include <stdarg.h>

typedef struct s_flags
{
	int	hash;
	int	point;
	int	minus;
	int	plus;
	int	num;
	int	num_dot;
	int	zero;
} t_flags;


int	ft_printf(char	const *str, ...);
int	ft_detec_flags_plus(char const *str, int *i, va_list list, t_flags *flags);
void	ft_detec_arguments(char const **str, int *i, va_list list, t_flags **flags);
void	ft_detec_flags(char const *str, t_flags *flags);

int	ft_printstring(va_list list, int *i, t_flags *flags);
int	ft_printchar(va_list list, int *i, t_flags *flags);
int	ft_printpointer(va_list list, int *i, t_flags *flags);
int	ft_printinteger(va_list list, int *len, t_flags *flags);
int	ft_printunsigned(va_list list, int *len, t_flags *flags);
int	ft_printhexa(va_list list, char c, t_flags *flags);

void	ft_zero(int num, char c);
# endif