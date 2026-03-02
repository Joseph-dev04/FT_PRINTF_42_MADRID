/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:23:25 by jopajuel          #+#    #+#             */
/*   Updated: 2026/03/02 13:01:27 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(char	const *str, ...);
void	ft_detec_args(char const **str, int *i, va_list list);

int		ft_printstring(va_list list, int *len);
int		ft_printchar(va_list list, int *len);
int		ft_printpointer(va_list list, int *len);
int		ft_printinteger(va_list list, int *len);
int		ft_printunsigned(va_list list, int *len);
int		ft_printhexa(va_list list, char c, int *len);

void	print_padding(int n, char c, int *len);
void	ft_putchar_len(char c, int *len);
void	ft_putnbr_unsigned_len(unsigned long n, int *len);
int		ft_numlen_base(unsigned long n, int base);
int		ft_numlen_base_int(unsigned int n, int base);
void	ft_putnbr_base_len(unsigned long n, char *base, int *len);
void	ft_putnbr_unsigned_len(unsigned long n, int *len);
#endif