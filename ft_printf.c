/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:39:43 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/29 12:47:35 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
/*
size_t	ft_stringlen(va_list list)
{
	return (ft_strlen(va_arg(list, char *)));
}

int	ft_val_len(va_list list, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 's')
			return (ft_stringlen(list));
		else if (str[i] == 'x' || str[i] == 'X')
			return ;
		else if (str[i] == 'c')
			return (1);
		else if (str[i] == 'd' || str[i] == 'i')
			return ;
		else if (str[i] == 'u')
			return ;
		else if (str[i] == 'p')
			return ;
		i++;
	}
	return (0);
}
*/
int	ft_printf(char	const *str, ...)
{
	va_list	print;
	int	i;

	i = 0;
	va_start(print, str);
	while (*str)
	{
		while (*str && *str != '%')
		{
			ft_putchar_fd(*str, 0);
			str++;
			i++;
		}
		if (*str && *++str != '%')
			ft_detec_arguments(&str, &i, print);
		else if (*str == '%')
			ft_putchar_fd('%', 0);
		str++;
		i++;
	}
	return (i);
}

