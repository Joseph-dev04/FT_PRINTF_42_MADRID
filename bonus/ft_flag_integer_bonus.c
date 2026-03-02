/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_integer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 10:22:04 by jopajuel          #+#    #+#             */
/*   Updated: 2026/03/02 11:03:43 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_d_init(t_d *d, int n, t_flags *f)
{
	d->nb = n;
	d->sign = 0;
	if (d->nb < 0)
	{
		d->sign = '-';
		d->nb = -d->nb;
	}
	else if (f->plus)
		d->sign = '+';
	else if (f->space)
		d->sign = ' ';
}

int	ft_numlen_base(unsigned long n, int base)
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

static void	ft_d_lengths(t_d *d, t_flags *f)
{
	d->num_len = ft_numlen_base(d->nb, 10);
	if (f->point && f->num_dot == 0 && d->nb == 0)
		d->num_len = 0;
	d->zeros = 0;
	if (f->point && f->num_dot > d->num_len)
		d->zeros = f->num_dot - d->num_len;
	d->padding = d->num_len + d->zeros;
	if (d->sign)
		d->padding++;
	if (f->num > d->padding)
		d->padding = f->num - d->padding;
	else
		d->padding = 0;
}

static void	ft_d_print_left(t_d *d, t_flags *f, int *len)
{
	if (!f->minus)
	{
		if (f->zero && !f->point)
		{
			if (d->sign)
			{
				ft_putchar_len(d->sign, len);
				d->sign = 0;
			}
			print_padding(d->padding, '0', len);
		}
		else
			print_padding(d->padding, ' ', len);
	}
}

int	ft_printinteger(va_list ap, int *len, t_flags *f)
{
	t_d		d;
	int		n;

	n = va_arg(ap, int);
	ft_d_init(&d, n, f);
	ft_d_lengths(&d, f);
	ft_d_print_left(&d, f, len);
	if (d.sign)
		ft_putchar_len(d.sign, len);
	print_padding(d.zeros, '0', len);
	if (!(f->point && f->num_dot == 0 && n == 0))
		ft_putnbr_unsigned_len(d.nb, len);
	if (f->minus)
		print_padding(d.padding, ' ', len);
	return (1);
}
