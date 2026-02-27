/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 10:21:05 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/27 10:21:39 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_u_lengths(t_u *u, t_flags *f)
{
	u->num_len = ft_numlen_base(u->nb, 10);
	if (f->point && f->num_dot == 0 && u->nb == 0)
		u->num_len = 0;
	u->zeros = 0;
	if (f->point && f->num_dot > u->num_len)
		u->zeros = f->num_dot - u->num_len;
	u->padding = u->num_len + u->zeros;
	if (f->num > u->padding)
		u->padding = f->num - u->padding;
	else
		u->padding = 0;
}

static void	ft_u_print_left(t_u *u, t_flags *f, int *len)
{
	if (!f->minus)
	{
		if (f->zero && !f->point)
			print_padding(u->padding, '0', len);
		else
			print_padding(u->padding, ' ', len);
	}
}

int	ft_printunsigned(va_list ap, int *len, t_flags *f)
{
	t_u	u;

	u.nb = va_arg(ap, unsigned int);
	ft_u_lengths(&u, f);
	ft_u_print_left(&u, f, len);
	print_padding(u.zeros, '0', len);
	if (!(f->point && f->num_dot == 0 && u.nb == 0))
		ft_putnbr_unsigned_len(u.nb, len);
	if (f->minus)
		print_padding(u.padding, ' ', len);
	return (1);
}