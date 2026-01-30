/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detec_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:44:47 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/30 15:11:13 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
#include <stdio.h>
void	ft_detec_flags(char const *str, t_flags *flags)
{
	if (*str == '-')
		flags->minus = 1;
	else if (flags->minus == 0 && *str == '0' && !flags->num)
		flags->zero = 1;
	else if (*str == '.')
		flags->point = 1;
	else if (*str == '+')
		flags->plus = 1;
	else if (*str == '#')
		flags->hash = 1;
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
