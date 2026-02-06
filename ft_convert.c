/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:40:28 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/06 13:30:49 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(va_list list, int *len, t_flags *flags)
{
	char	*src;

	src = va_arg(list, char *);
	if (!src)
	{
		if ((flags->num && flags->point) && !flags->num_dot)
		{
			ft_zero(flags->num, ' ', len);
			return (1);
		}
		else if ((flags->num && flags->point) && (flags->num_dot < 6 && flags->num > flags->num_dot))
		{
			ft_zero(flags->num, ' ', len);
			return (1);
		}
		else if ((flags->num && flags->point) && (flags->num_dot >=6 && flags->num > flags->num_dot))
		{
			flags->num -= 6;
			if (flags->minus)
			{
				ft_putstr_fd("(null)", 1);
				ft_zero(flags->num, ' ', len);
			}else
			{
				ft_zero(flags->num, ' ', len);
				ft_putstr_fd("(null)", 1);
			}
			(*len) += 6;
			return (1);
		}
		flags->num -= 6;
		ft_flags_caracters(flags, src, len);
		return (1);
	}
	if ((!flags->minus && flags->num_dot ) && flags->num_dot < (int)ft_strlen(src))
	{
		flags->num -= flags->num_dot;
	}
	else if ((flags->minus && flags->num_dot ) && flags->num_dot < (int)ft_strlen(src))
	{
		flags->num -= flags->num_dot;
	}
	else if ((flags->num && flags->point) && !flags->num_dot)
	{
		ft_zero(flags->num, ' ', len);
		return (1);
	}
	else if ((flags->point && flags->minus) && (flags->num_dot == 0 && flags->num == flags->num_dot))
	{
		return (1);
	}
	else
		flags->num -= ft_strlen(src);
	ft_flags_caracters(flags, src, len);
	//(*len) += ft_strlen(src);
	return (1);
}

int	ft_printchar(va_list list, int *len, t_flags *flags)
{
	char	c;

	c = va_arg(list, int);
	ft_flags_trings(flags, c, len);
	//(*len)++;
	return (1);
}

int	ft_lenpoint(unsigned long long num)
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
#include <stdio.h>
void	ft_flags_pointer(t_flags *flags, unsigned long long i, char *str, int *len)
{
	if (flags->minus)
	{
		ft_putstr_fd("0x", 1);
		if (flags->num > flags->num_dot && flags->num_dot > ft_lenpoint(i))
		{

			ft_zero(flags->num_dot - ft_lenpoint(i), '0', len);
			ft_long(str, i, len);
			ft_zero(flags->num - (flags->num_dot - ft_lenpoint(i)), ' ', len);
		}
		else if (flags->num < flags->num_dot && flags->num_dot > ft_lenpoint(i))
		{
			ft_zero(flags->num_dot - ft_lenpoint(i), '0', len);
			ft_long(str, i, len);
		}
		else if (flags->num > flags->num_dot && flags->num_dot == ft_lenpoint(i))
		{
			ft_zero(flags->num, ' ', len);
		}
		else if (flags->zero == 0)
		{
			ft_long(str, i, len);
			if (i == 0)
				flags->num--;
			ft_zero(flags->num - (ft_lenpoint(i) + 2), ' ', len);
		}
	}
	else if(flags->point)
	{
		if (flags->num_dot > ft_lenpoint(i) && flags->num_dot > flags->num)
		{

			ft_zero(flags->num_dot - ft_lenpoint(i), '0', len);
			ft_long(str, i, len);
		
		}
		else if (flags->num > flags->num_dot)
		{
			if (flags->num_dot < ft_lenpoint(i))
			{
				ft_zero(flags->num, ' ', len);
				ft_long(str, i, len);
			}
			else
			{
				ft_zero(flags->num - (flags->num_dot - ft_lenpoint(i)), ' ', len);
				ft_zero(flags->num_dot - ft_lenhexa(i), '0', len);
				ft_long(str, i, len);
			}
		}
		else
		{
			ft_putstr_fd("0x", 1);
			ft_long(str, i, len);
		}
	}
	else if (flags->zero)
	{
		if (i == 0)
		{
			ft_zero(flags->num, '0', len);
		}
		else
		{
			ft_zero(flags->num, '0', len);
			ft_long(str, i, len);
		}
	}
	else
	{
		if (flags->num)
		{
			//printf("*%i*",flags->num);
				ft_zero(flags->num - (ft_lenpoint(i) + 2), ' ', len);
				ft_putstr_fd("0x", 1);
				ft_long(str, i, len);
		}
		else
		{
			ft_zero(flags->num, ' ', len);
			ft_putstr_fd("0x", 1);
			ft_long(str, i, len);
		}
	}
}


int	ft_printpointer(va_list list, int *len, t_flags *flags)
{
	void				*p;
	unsigned long long	num;

	p = va_arg(list, void *);
	if (!p)
	{
		if (flags->minus)
		{
			ft_putstr_fd("(nil)", 1);
			(*len) += 5;
			if (flags->num > 5)
			ft_zero(flags->num - 5, ' ', len);
			return (1);
		}
		if (flags->num > 5)
			ft_zero(flags->num - 5, ' ', len);
		ft_putstr_fd("(nil)", 1);
		(*len) += 5;
		return (1);
	}
	num = (unsigned long long)p;
	//ft_putstr_fd("0x", 1);
	(*len) += 2;
	ft_flags_pointer(flags, num, "0123456789abcdef", len);
	//ft_long("0123456789abcdef", num, len);
	//flags->num = 1;
	return (1);
}

int	ft_printinteger(va_list list, int *len, t_flags *flags)
{
	int		i;
	char	*str;
	int		lenstr;

	i = va_arg(list, int);
	str = ft_itoa(i);
	lenstr = ft_strlen(str);
	if (flags->plus && i >= 0)
		lenstr++;
	(*len) += lenstr;
	if (i != 0)
		flags->num -= lenstr;
	if ((flags->plus && i >= 0) && (flags->num == 0 || flags->minus))
		ft_putchar_fd('+', 1);
	ft_flags_int(flags, str, len, i);
	free(str);
	return (1);
}

int	ft_printunsigned(va_list list, int *len, t_flags *flags)
{
	unsigned int	i;
	char			*str;

	i = va_arg(list, unsigned int);
	str = ft_utoa(i);
	(*len) += ft_strlen(str);
	if (flags->num)
		flags->num -= ft_strlen(str);
	ft_flags_unint(flags, str, len, i);
	free(str);
	return (1);
}
