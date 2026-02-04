/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:28:47 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/04 12:05:11 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_caracters(t_flags *flags, char *src, int *i)
{
	if (flags->minus)
	{
		ft_putstr_fd(src, 1);
		*i = ft_strlen(src);
		if (flags->zero == 0)
			ft_zero(flags->num, ' ', i);
	}
	else if (flags->num > (int)ft_strlen(src) && flags->zero)
	{
		ft_zero(flags->num, '0', i);
		ft_putstr_fd(src, 1);
	}
	else
	{
		ft_zero(flags->num, ' ', i);
		ft_putstr_fd(src, 1);
	}
}

void	ft_flags_trings(t_flags *flags, char c, int *i)
{
	if (flags->minus)
	{
		ft_putchar_fd(c, 1);
		*i = 1;
		if (flags->zero == 1)
			ft_zero(flags->num, ' ', i);
	}
	else if (flags->num > 1 && flags->zero)
	{
		ft_zero(flags->num, '0', i);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_zero(flags->num, ' ', i);
		ft_putchar_fd(c, 1);
	}
}

void	ft_flags_int(t_flags *flags, char *str, int *i, int len)
{
	ft_check_num(&str, len);
	if (flags->minus)
	{
		ft_putstr_fd(str, 1);
		if (flags->zero == 0)
			ft_zero(flags->num, ' ', i);
	}
	else if (flags->num >= (int)ft_strlen(str) && flags->zero)
	{
		if (flags->plus)
			ft_putchar_fd('+', 1);
		ft_zero(flags->num, '0', i);
		ft_putstr_fd(str, 1);
	}
	else
	{
		ft_zero(flags->num, ' ', i);
		if (flags->plus && len >= 0)
			ft_putchar_fd('+', 1);
		ft_putstr_fd(str, 1);
	}
}

void	ft_flags_unint(t_flags *flags, char *str, int *i, int len)
{
	if (flags->minus)
	{
		ft_putstr_fd(str, 1);
		*i = 1;
		if (flags->zero == 0)
			ft_zero(flags->num, ' ', i);
	}
	else if (flags->num >= (int)ft_strlen(str) && flags->zero)
	{
		if (flags->plus)
			ft_putchar_fd('+', 1);
		ft_zero(flags->num, '0', i);
		ft_putstr_fd(str, 1);
	}
	else
	{
		ft_zero(flags->num, ' ', i);
		if (flags->plus && len >= 0)
			ft_putchar_fd('+', 1);
		ft_putstr_fd(str, 1);
	}
}

void	ft_flags_hexa(t_flags *flags, unsigned int i, char *str, int *len)
{
	if (flags->minus)
	{
		if (flags->hash)
			ft_putstr_fd("0x", 1);
		ft_hexa(str, i, len);
		if (flags->zero == 0)
			ft_zero(flags->num, ' ', len);
	}
	else if (flags->zero)
	{
		if (flags->hash)
			ft_putstr_fd("0x", 1);
		ft_zero(flags->num, '0', len);
		ft_hexa(str, i, len);
	}
	else
	{
		ft_zero(flags->num, ' ', len);
		if (flags->hash)
			ft_putstr_fd("0x", 1);
		ft_hexa(str, i, len);
	}
}
