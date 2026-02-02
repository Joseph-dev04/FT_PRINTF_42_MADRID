/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:40:28 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/02 12:09:08 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
#include <stdio.h>
void	ft_flags_caracters(t_flags *flags, char *src, int * i)
{
	if (flags->minus)
	{
		ft_putstr_fd(src, 0);
		*i = ft_strlen(src);
		if (flags->zero == 0)
			ft_zero(flags->num, ' ');
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
}



void	ft_flags_trings(t_flags *flags, char c, int * i)
{
	if (flags->minus)
	{
		ft_putchar_fd(c, 0);
		*i = 1;
		if (flags->zero == 0)
			ft_zero(flags->num, ' ');
	}
	else if (flags->num > 1 && flags->zero)
	{
		ft_zero(flags->num, '0');
		ft_putchar_fd(c, 0);
	}
	else
	{
		ft_zero(flags->num, ' ');
		ft_putchar_fd(c, 0);
	}
}

void	ft_check_num(char **str, int len)
{
	if  (len < 0)
	{
		ft_putchar_fd('-', 0);
		(*str)++;
	}
}

void	ft_flags_int(t_flags *flags, char *str, int * i, int len)
{
	ft_check_num(&str, len);
	if (flags->minus)
	{
		ft_putstr_fd(str, 0);
		*i = 1;
		if (flags->zero == 0)
			ft_zero(flags->num, ' ');
	}
	else if (flags->num > ft_strlen(str) && flags->zero)
	{
		if (flags->plus)
			ft_putchar_fd('+', 0);
		ft_zero(flags->num, '0');
		ft_putstr_fd(str, 0);
	}
	else
	{
		ft_zero(flags->num, ' ');
		if (flags->plus && len >= 0)
			ft_putchar_fd('+', 0);
		ft_putstr_fd(str, 0);
	}
}

int	ft_printstring(va_list list, int *len, t_flags *flags)
{
	char	*src;
	int	i;

	i = 0;
	src = va_arg(list, char *);
	flags->num -= ft_strlen(src);
	ft_flags_caracters(flags, src, &i);
	len += i;
	return (1);
}

int	ft_printchar(va_list list, int *len, t_flags *flags)
{
	char	c;

	c = va_arg(list, int);
	//ft_putchar_fd(c, 0);
	flags->num -= 1;
	ft_flags_trings(flags, c, len);
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
	int	lenstr;

	i = va_arg(list, int);
	str = ft_itoa(i);
	lenstr = ft_strlen(str);
	//printf("%i %s\n", i, str);
	if (flags->plus && i >= 0)
		lenstr++;
	len += lenstr;
	flags->num -= lenstr;
	if ((flags->plus && i >= 0) && (flags->num == 0 || flags->minus))
		ft_putchar_fd('+', 0);
	ft_flags_int(flags, str, len, i);
	//ft_putstr_fd(str,0);
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

void	ft_hexa(char *str, int i)
{
	int	j;

	j = 0;
	if (i < 16)
		ft_putchar_fd(str[i], 0);
	else
	{
		ft_hexa(str, i / 16);
		ft_putchar_fd(str[i % 16], 0);		
	}
}
void	ft_flags_hexa(t_flags *flags, int i, char *str)
{
	if (flags->minus)
	{
		if (flags->hash)
			ft_putstr_fd("0x", 0);
		ft_hexa(str, i);
		if (flags->zero == 0)
			ft_zero(flags->num, ' ');
	}
	else if (flags->zero)
	{
		if (flags->hash)
			ft_putstr_fd("0x", 0);
		ft_zero(flags->num, '0');
		ft_hexa(str, i);
	}
	else
	{
		ft_zero(flags->num, ' ');
		if (flags->hash)
			ft_putstr_fd("0x", 0);
		ft_hexa(str, i);
	}
}


int	ft_len(int num)
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

int	ft_printhexa(va_list list, char c, t_flags *flags)
{
	int	num;
	char *str;
	
	num = va_arg(list, int);
	flags->num -= ft_len(num);
	if (flags->hash)
		flags->num -= 2;
	if (c == 'x')
	{
		str = "0123456789abcdef";
		ft_flags_hexa(flags, num, str);
		//ft_hexa(str, num);
	}
	else
	{
		str = "0123456789ABCDEF";
		ft_flags_hexa(flags, num, str);
		//ft_hexa(str, num);
	}
	return (1);
}