/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:34:19 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/04 11:40:14 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenun(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			i++;
	}
	return (++i);
}

char	*ft_utoa(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	i = ft_lenun(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}

void	ft_check_num(char **str, int len)
{
	if (len < 0)
	{
		ft_putchar_fd('-', 1);
		(*str)++;
	}
}

int	ft_printhexa(va_list list, char c, int *i, t_flags *flags)
{
	unsigned int	num;
	char			*str;

	num = va_arg(list, int);
	flags->num -= ft_lenhexa(num);
	if (flags->hash)
		flags->num -= 2;
	if (c == 'x')
	{
		str = "0123456789abcdef";
		ft_flags_hexa(flags, num, str, i);
	}
	else
	{
		str = "0123456789ABCDEF";
		ft_flags_hexa(flags, num, str, i);
	}
	return (1);
}
