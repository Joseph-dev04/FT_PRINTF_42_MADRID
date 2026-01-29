/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detec_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:43:13 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/29 12:39:19 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

void	ft_detec_flags_plus(char const *str, int *i, va_list list)
{
	if (*str == 's')
		ft_printstring(list, i);
	else if (*str == 'c')
		ft_printchar(list, i);
	else if (*str == 'p')
		ft_printpointer(list, i);
	else if (*str == 'd' && *str == 'i')
		ft_printinteger(list, i);
	else if (*str == 'u')
		ft_printunsigned(list, i);
	else if (*str == 'x' || *str == 'X')
		ft_printhexa(list, *str);
	str++;
}

void	ft_detec_arguments(char const **str, int *i, va_list list)
{
	int	j;
	
	j = 0;
	while (*str)
	{
		//ft_detec_flags(&str, i);
		ft_detec_flags_plus(*str, i, list);
		str++;
		i++;
	}
}