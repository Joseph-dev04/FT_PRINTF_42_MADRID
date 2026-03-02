/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:39:43 by jopajuel          #+#    #+#             */
/*   Updated: 2026/03/02 11:04:00 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_porcentage(int *i)
{
	ft_putchar_fd('%', 1);
	(*i)++;
}

int	ft_printf(char	const *str, ...)
{
	va_list	print;
	t_flags	flags;
	int		i;

	i = 0;
	va_start(print, str);
	while (*str)
	{
		if (*str && *str == '%')
		{
			str++;
			if (*str != '%')
				ft_detec_args(&str, &i, print, &flags);
			else
				ft_porcentage(&i);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			i++;
		}
		str++;
	}
	va_end(print);
	return (i);
}
