/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detec_arguments_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:43:13 by jopajuel          #+#    #+#             */
/*   Updated: 2026/03/02 11:03:26 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_detec_plus(char const *str, int *i, va_list list, t_flags *flags)
{
	if (*str == 's')
		return (ft_printstring(list, i, flags));
	else if (*str == 'c')
		return (ft_printchar(list, i, flags));
	else if (*str == 'p')
		return (ft_printpointer(list, i, flags));
	else if (*str == 'd' || *str == 'i')
		return (ft_printinteger(list, i, flags));
	else if (*str == 'u')
		return (ft_printunsigned(list, i, flags));
	else if (*str == 'x' || *str == 'X')
		return (ft_printhexa(list, *str, i, flags));
	else if (*str && *str == '%')
	{
		ft_putchar_fd('%', 1);
		(*i)++;
		return (-1);
	}
	return (0);
}

void	ft_init_struct(t_flags *flags)
{
	flags->hash = 0;
	flags->minus = 0;
	flags->num = 0;
	flags->num_dot = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->point = 0;
	flags->iter = 0;
	flags->space = 0;
}

void	ft_detec_args(char const **str, int *i, va_list list, t_flags *flags)
{
	ft_init_struct(flags);
	while (*str && !ft_detec_plus(*str, i, list, flags))
	{
		ft_detec_flags(*str, flags);
		(*str)++;
	}
}
