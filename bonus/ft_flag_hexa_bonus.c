/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hexa_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:56:31 by jopajuel          #+#    #+#             */
/*   Updated: 2026/03/02 11:03:38 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

void	ft_putnbr_base_len(unsigned long n, char *base, int *len)
{
	if (n >= 16)
		ft_putnbr_base_len(n / 16, base, len);
	ft_putchar_len(base[n % 16], len);
}

static void	ft_x_lengths(t_x *x, t_flags *f)
{
	x->num_len = ft_numlen_base_int(x->nb, 16);
	if (f->point && f->num_dot == 0 && x->nb == 0)
		x->num_len = 0;
	x->zeros = 0;
	if (f->point && f->num_dot > x->num_len)
		x->zeros = f->num_dot - x->num_len;
	x->prefix = 0;
	if (f->hash && x->nb != 0)
		x->prefix = 2;
	x->padding = x->num_len + x->zeros + x->prefix;
	if (f->num > x->padding)
		x->padding = f->num - x->padding;
	else
		x->padding = 0;
}

static void	ft_x_print_left(t_x *x, t_flags *f, int upper, int *len)
{
	if (!f->minus)
	{
		if (f->zero && !f->point)
		{
			if (x->prefix)
			{
				if (upper == 'X')
					write(1, "0X", 2);
				else
					write(1, "0x", 2);
				*len += 2;
				x->prefix = 0;
			}
			print_padding(x->padding, '0', len);
		}
		else
			print_padding(x->padding, ' ', len);
	}
}

int	ft_printhexa(va_list ap, char upper, int *len, t_flags *f)
{
	t_x		x;
	char	*base;

	x.nb = va_arg(ap, unsigned int);
	if (upper == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ft_x_lengths(&x, f);
	ft_x_print_left(&x, f, upper, len);
	if (x.prefix)
	{
		if (upper == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		*len += 2;
	}
	print_padding(x.zeros, '0', len);
	if (!(f->point && f->num_dot == 0 && x.nb == 0))
		ft_putnbr_base_len(x.nb, base, len);
	if (f->minus)
		print_padding(x.padding, ' ', len);
	return (1);
}
