/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:23:25 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/29 12:48:13 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FT_PRINTF_H
# define	FT_PRINTF_H
#include <stdarg.h>
int	ft_printf(char	const *str, ...);
void	ft_detec_flags_plus(char const *str, int *i, va_list list);
void	ft_detec_arguments(char const **str, int *i, va_list list);

void	ft_printstring(va_list list, int *i);
void	ft_printchar(va_list list, int *i);
void	ft_printpointer(va_list list, int *i);
void	ft_printinteger(va_list list, int *len);
void	ft_printunsigned(va_list list, int *len);
void	ft_printhexa(va_list list, char c);
# endif