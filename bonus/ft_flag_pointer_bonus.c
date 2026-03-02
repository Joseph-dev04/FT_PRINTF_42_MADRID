/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_pointer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:09:48 by jopajuel          #+#    #+#             */
/*   Updated: 2026/03/02 11:03:50 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_p_lengths(t_p *p, t_flags *f)
{
	p->num_len = ft_numlen_base(p->nb, 16);
	if (f->point && f->num_dot == 0 && p->nb == 0)
		p->num_len = 0;
	p->zeros = 0;
	if (f->point && f->num_dot > p->num_len)
		p->zeros = f->num_dot - p->num_len;
	if (p->nb != 0)
		p->padding = p->num_len + p->zeros + 2;
	else
		p->padding = p->num_len + p->zeros;
	if (f->num > p->padding && p->nb != 0)
		p->padding = f->num - p->padding;
	else if (f->num > (int)ft_strlen("(nil)") && p->nb == 0)
		p->padding = f->num - (int)ft_strlen("(nil)");
	else
		p->padding = 0;
}

static void	ft_p_print_left(t_p *p, t_flags *f, int *len)
{
	if (!f->minus)
	{
		if ((f->zero && !f->point) && p->nb != 0)
		{
			write(1, "0x", 2);
			*len += 2;
			print_padding(p->padding, '0', len);
			return ;
		}
		print_padding(p->padding, ' ', len);
	}
	if (p->nb != 0)
	{
		write(1, "0x", 2);
		*len += 2;
	}
}

int	ft_printpointer(va_list ap, int *len, t_flags *f)
{
	t_p	p;

	p.nb = (unsigned long)va_arg(ap, void *);
	ft_p_lengths(&p, f);
	ft_p_print_left(&p, f, len);
	print_padding(p.zeros, '0', len);
	if (!(f->point && f->num_dot == 0 && p.nb == 0) && p.nb != 0)
		ft_putnbr_base_len(p.nb, "0123456789abcdef", len);
	if (p.nb == 0)
		(*len) += write (1, "(nil)", 5);
	if (f->minus)
		print_padding(p.padding, ' ', len);
	return (1);
}
