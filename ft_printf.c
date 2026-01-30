/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:39:43 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/30 12:36:38 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

void	ft_porcentage(char const **str,int *i)
{
	ft_putchar_fd('%', 0);
	str++;
	i++;
}

int	ft_printf(char	const *str, ...)
{
	va_list	print;
	t_flags	*flags;
	int	i;

	i = 0;
	va_start(print, str);
	while (*str)
	{
		if (*str && *str == '%')
		{
			str++;
			if (*str != '%')
				ft_detec_arguments(&str, &i, print, &flags);
			else
				ft_porcentage(&str, &i);
		}
		ft_putchar_fd(*str, 0);
		str++;
		i++;
	}
	return (i);
}

