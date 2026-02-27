/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:46:03 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/27 10:27:11 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding(int n, char c, int *len)
{
	while (n-- > 0)
	{
		write(1, &c, 1);
		(*len)++;
	}
}

void	ft_zero(int num, char c, int *i)
{
	while (num > 0)
	{
		(*i)++;
		ft_putchar_fd(c, 1);
		num--;
	}
}

void	ft_hexa(char *str, unsigned int i, int *len)
{
	if (i < 16)
	{
		(*len)++;
		ft_putchar_fd(str[i], 1);
	}
	else
	{
		(*len)++;
		ft_hexa(str, i / 16, len);
		ft_putchar_fd(str[i % 16], 1);
	}
}

int	ft_lenhexa(int num)
{
	int	i;

	i = 0;
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}

void	ft_long(char *str, unsigned long long i, int *len)
{
	if (i < 16)
	{
		(*len)++;
		ft_putchar_fd(str[i], 1);
	}
	else
	{
		(*len)++;
		ft_long(str, i / 16, len);
		ft_putchar_fd(str[i % 16], 1);
	}
}
