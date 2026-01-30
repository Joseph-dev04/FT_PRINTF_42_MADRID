/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:40:28 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/30 15:26:38 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

int	ft_printstring(va_list list, int *len, t_flags *flags)
{
	char	*src;
	int	i;

	i = 0;
	src = va_arg(list, char *);
	flags->num -= ft_strlen(src);
	if (flags->minus)
	{
		ft_putstr_fd(src, 0);
		i = ft_strlen(src);
	}
	else if (flags->num > ft_strlen(src) && flags->zero)
	{
		ft_zero(flags->num, '0');
		ft_putstr_fd(src, 0);
	}
	else
	{
		ft_zero(flags->num, ' ');
		ft_putstr_fd(src, 0);
	}
	len += i;
	return (1);
}

int	ft_printchar(va_list list, int *len, t_flags *flags)
{
	ft_putchar_fd(va_arg(list, int), 0);
	len++;
	return (1);
}
int	ft_printpointer(va_list list, int *len, t_flags *flags)
{
	void	*p;
	char	*str;
	
	p = va_arg(list, void *);
	ft_putstr_fd("0x",0);
	len += 3;
	str = (char *)p + 2;
	while (*str)
	{
		ft_putchar_fd(*str,0);
		str++;
		len++;
	}
	return (1);
}

int	ft_printinteger(va_list list, int *len, t_flags *flags)
{
	int	i;
	char	*str;

	i = va_arg(list, int);
	str = ft_itoa(i);
	len += ft_strlen(str);
	ft_putstr_fd(str,0);
	free(str);
	return (1);
}

int	ft_printunsigned(va_list list, int *len, t_flags *flags)
{
	int i;
	char	*str;

	i = va_arg(list, unsigned int);
	str = ft_itoa(i);
	len += ft_strlen(str);
	ft_putstr_fd(str,0);
	free(str);
	return (1);
}

int	ft_hexa(char *str, int i)
{
	int	j;

	j = 0;
	if (i < 16)
	{
		ft_putchar_fd(str[i], 0);
		j++;
	}
	else
	{
		ft_hexa(str, i / 16);
		ft_putchar_fd(str[i % 16], 0);
		j++;		
	}
	return (j);
}

int	ft_printhexa(va_list list, char c, t_flags *flags)
{
	int	num;
	char *str;
	
	num = va_arg(list, int);
	if (c == 'x')
	{
		str = "012346789abcdef";
		ft_hexa(str, num);
	}
	else
	{
		str = "0123456789ABCDEF";
		ft_hexa(str, num);
	}
	return (1);
}