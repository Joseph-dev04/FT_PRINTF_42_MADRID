/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:40:28 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/04 11:40:20 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(va_list list, int *len, t_flags *flags)
{
	char	*src;
	int		i;

	i = 0;
	src = va_arg(list, char *);
	if (src == NULL)
	{
		ft_putstr_fd("(null)", 1);
		(*len) += 6;
		return (1);
	}
	flags->num -= ft_strlen(src);
	ft_flags_caracters(flags, src, &i);
	(*len) += ft_strlen(src);
	return (1);
}

int	ft_printchar(va_list list, int *len, t_flags *flags)
{
	char	c;

	c = va_arg(list, int);
	flags->num -= 1;
	ft_flags_trings(flags, c, len);
	(*len)++;
	return (1);
}

int	ft_printpointer(va_list list, int *len, t_flags *flags)
{
	void				*p;
	unsigned long long	num;

	p = va_arg(list, void *);
	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		(*len) += 5;
		return (1);
	}
	num = (unsigned long long)p;
	ft_putstr_fd("0x", 1);
	(*len) += 2;
	ft_long("0123456789abcdef", num, len);
	flags->num = 1;
	return (flags->num);
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
	flags->num -= lenstr;
	if ((flags->plus && i >= 0) && (flags->num == 0 || flags->minus))
		ft_putchar_fd('+', 0);
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
	flags->num -= ft_strlen(str);
	ft_flags_unint(flags, str, len, i);
	free(str);
	return (1);
}
