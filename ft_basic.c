/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:44:03 by jopajuel          #+#    #+#             */
/*   Updated: 2026/03/02 12:59:22 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printinteger(va_list ap, int *len)
{
	long		n;

	n = va_arg(ap, int);
	if (n < 0)
	{
		ft_putchar_len('-', len);
		n *= -1;
	}
	ft_putnbr_unsigned_len(n, len);
	return (1);
}

int	ft_printpointer(va_list ap, int *len)
{
	unsigned long	nb;

	nb = (unsigned long)va_arg(ap, void *);
	if (nb == 0)
	{
		(*len) += write (1, "(nil)", 5);
		return (1);
	}
	ft_putstr_fd("0x", 1);
	(*len) += 2;
	ft_putnbr_base_len(nb, "0123456789abcdef", len);
	return (1);
}

int	ft_numlen_base_int(unsigned int n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ft_printunsigned(va_list ap, int *len)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	ft_putnbr_unsigned_len(nb, len);
	return (1);
}
