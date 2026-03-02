/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detec_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:44:47 by jopajuel          #+#    #+#             */
/*   Updated: 2026/03/02 11:03:31 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_detec_flags(char const *str, t_flags *flags)
{
	if (*str == '-')
		flags->minus = 1;
	else if (flags->minus == 0 && *str == '0' && !flags->num && !flags->point)
		flags->zero = 1;
	else if (*str == '.')
		flags->point = 1;
	else if (*str == '+')
		flags->plus = 1;
	else if (*str == '#')
		flags->hash = 1;
	else if (*str == ' ')
		flags->space = 1;
	if (flags->point && (*str >= '0' && *str <= '9'))
	{
		flags->num_dot = flags->num_dot * 10 + (*str - '0');
		str++;
	}
	else if (*str >= '0' && *str <= '9')
	{
		flags->num = flags->num * 10 + (*str - '0');
		str++;
	}
}
