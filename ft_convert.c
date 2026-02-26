/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:40:28 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/05 12:05:52 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static char	*ft_s_get_string(char *str)
{
	if (!str)
		return ("(null)");
	return (str);
}
static int	ft_s_get_print_len(char *str, t_flags *f)
{
	int	len;

	len = ft_strlen(str);
	if (f->point)
	{
		if (f->num_dot == 0)
			return (0);
		if (f->num_dot < len)
			return (f->num_dot);
	}
	return (len);
}
int	ft_printstring(va_list ap, int *len, t_flags *f)
{
    char	*str;
	int		print_len;
	int		padding;

	str = va_arg(ap, char *);
	str = ft_s_get_string(str);
	print_len = ft_s_get_print_len(str, f);
	padding = 0;
	if (f->num > print_len)
		padding = f->num - print_len;
	if (!f->minus)
		print_padding(padding, ' ', len);
	write(1, str, print_len);
	*len += print_len;
	if (f->minus)
		print_padding(padding, ' ', len);
	return (1);
}

int	ft_printchar(va_list ap, int *len, t_flags *f)
{
	char    c;
    int     padding;

    c = (char)va_arg(ap, int);

    padding = 0;
    if (f->num > 1)
        padding = f->num - 1;

    if (!f->minus)
    {
        if (f->zero)
            print_padding(padding, '0', len);
        else
            print_padding(padding, ' ', len);
    }

    write(1, &c, 1);
    (*len)++;

    if (f->minus)
        print_padding(padding, ' ', len);

    return (1);
}

static int	ft_numlen_base_ull(unsigned long long n, int base_len)
{
	int	len;

	len = 1;
	while (n >= (unsigned long long)base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_utoa_base_ull(unsigned long long n, char *base)
{
	char	*result;
	int		base_len;
	int		len;

	base_len = 0;
	while (base[base_len])
		base_len++;

	len = ft_numlen_base_ull(n, base_len);

	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);

	result[len] = '\0';

	if (n == 0)
	{
		result[0] = base[0];
		return (result);
	}

	while (n > 0)
	{
		result[--len] = base[n % base_len];
		n /= base_len;
	}
	return (result);
}

int	ft_printpointer(va_list ap, int *len, t_flags *f)
{
	void                    *ptr;
    unsigned long long      addr;
    char                    *num_str;
    int                     num_len;
    int                     total_len;
    int                     padding;

    ptr = va_arg(ap, void *);

    // 🔹 Caso NULL
    if (!ptr)
    {
        int nil_len = 5; // "(nil)"
        padding = 0;

        if (f->num > nil_len)
            padding = f->num - nil_len;

        if (!f->minus)
            print_padding(padding, ' ', len);

        write(1, "(nil)", 5);
        (*len) += 5;

        if (f->minus)
            print_padding(padding, ' ', len);

        return (1);
    }

    // 🔹 Dirección válida
    addr = (unsigned long long)ptr;
    num_str = ft_utoa_base_ull(addr, "0123456789abcdef");
    num_len = ft_strlen(num_str);

    total_len = num_len + 2; // 2 por "0x"

    padding = 0;
    if (f->num > total_len)
        padding = f->num - total_len;

    // 🔹 PRINT

    if (!f->minus)
    {
        if (f->zero && !f->point)
        {
            // prefijo antes de ceros
            write(1, "0x", 2);
            (*len) += 2;
            print_padding(padding, '0', len);
        }
        else
            print_padding(padding, ' ', len);
    }

    // prefijo si no se imprimió antes
    if (!(f->zero && !f->point && !f->minus))
    {
        write(1, "0x", 2);
        (*len) += 2;
    }

    write(1, num_str, num_len);
    (*len) += num_len;

    if (f->minus)
        print_padding(padding, ' ', len);

    free(num_str);
    return (1);
}

void print_padding(int n, char c, int *len)
{
    while (n-- > 0)
    {
        write(1, &c, 1);
        (*len)++;
    }
}

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}
void	ft_putnbr_unsigned_len(unsigned long n, int *len)
{
	if (n >= 10)
		ft_putnbr_unsigned_len(n / 10, len);
	ft_putchar_len((n % 10) + '0', len);
}

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
int	ft_printinteger(va_list ap, int *len,t_flags *f)
{
	t_d	d;
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
