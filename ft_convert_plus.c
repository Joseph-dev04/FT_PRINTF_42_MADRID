/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:46:03 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/30 15:13:52 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

void	ft_zero(int num, char c)
{
	while (num >= 0)
	{
		ft_putchar_fd(c, 0);
		num--;
	}	
}
/*
int	ft_point(char *str)
{
	
}

int	ft_plus()
{
	
}

void	ft_minus()
{
	
}

int	ft_tab(char *str, va_list list, int *i, int j)
{
	ft_detec_flags_plus(str, i , list , j);
}

int	ft_hash()
{
	
}*/