/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:39:43 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/27 13:54:33 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

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

int main()
{
	return (ft_printf("ho", "xf", "zz"));
}
