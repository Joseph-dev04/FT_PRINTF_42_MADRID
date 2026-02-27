#include "ft_printf.h"

static void	ft_p_lengths(t_p *p, t_flags *f)
{
	p->num_len = ft_numlen_base(p->nb, 16);
	if (f->point && f->num_dot == 0 && p->nb == 0)
		p->num_len = 0;
	p->zeros = 0;
	if (f->point && f->num_dot > p->num_len)
		p->zeros = f->num_dot - p->num_len;
	p->padding = p->num_len + p->zeros + 2;
	if (f->num > p->padding)
		p->padding = f->num - p->padding;
	else
		p->padding = 0;
}

static void	ft_p_print_left(t_p *p, t_flags *f, int *len)
{
	if (!f->minus)
	{
		if (f->zero && !f->point)
		{
			write(1, "0x", 2);
			*len += 2;
			print_padding(p->padding, '0', len);
			return ;
		}
		print_padding(p->padding, ' ', len);
	}
	write(1, "0x", 2);
	*len += 2;
}

int	ft_printpointer(va_list ap, int *len, t_flags *f)
{
	t_p	p;

	p.nb = (unsigned long)va_arg(ap, void *);
	ft_p_lengths(&p, f);
	ft_p_print_left(&p, f, len);
	print_padding(p.zeros, '0', len);
	if (!(f->point && f->num_dot == 0 && p.nb == 0))
		ft_putnbr_base_len(p.nb, "0123456789abcdef", len);
	if (f->minus)
		print_padding(p.padding, ' ', len);
	return (1);
}
