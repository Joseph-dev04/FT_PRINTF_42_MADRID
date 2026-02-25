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

int	ft_printstring(va_list ap, int *len, t_flags *f)
{char    *str;
    int     str_len;
    int     print_len;
    int     padding;

    str = va_arg(ap, char *);

    if (!str)
        str = "(null)";

    str_len = ft_strlen(str);

    if (f->point)
    {
        if (f->num_dot == 0)
            print_len = 0;
        else if (f->num_dot < str_len)
            print_len = f->num_dot;
        else
            print_len = str_len;
    }
    else
        print_len = str_len;

    padding = 0;
    if (f->num > print_len)
        padding = f->num - print_len;

    if (!f->minus)
        print_padding(padding, ' ', len);

    if (print_len > 0)
    {
        write(1, str, print_len);
        (*len) += print_len;
    }

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
int ft_printinteger(va_list ap, int *len, t_flags *f)
{
    int     n;
    long    nb;
    char    *num_str;
    int     is_negative;
    int     num_len;
    int     precision_zeros;
    int     total_len;
    int     padding;
    char    sign;

    n = va_arg(ap, int);
    nb = n;

    is_negative = (nb < 0);
    sign = 0;

    if (is_negative)
    {
        sign = '-';
        nb = -nb;
    }
    else if (f->plus)
        sign = '+';

    num_str = ft_utoa_base((unsigned int)nb, "0123456789");
    num_len = ft_strlen(num_str);

    if (f->point && f->num_dot == 0 && n == 0)
        num_len = 0;

    precision_zeros = 0;
    if (f->point && f->num_dot > num_len)
        precision_zeros = f->num_dot - num_len;

    total_len = num_len + precision_zeros;
    if (sign)
        total_len++;

    padding = 0;
    if (f->num > total_len)
        padding = f->num - total_len;

    if (!f->minus)
    {
        if (f->zero && !f->point)
        {
            if (sign)
            {
                write(1, &sign, 1);
                (*len)++;
                sign = 0;
            }
            print_padding(padding, '0', len);
        }
        else
            print_padding(padding, ' ', len);
    }

    if (sign)
    {
        write(1, &sign, 1);
        (*len)++;
    }

    print_padding(precision_zeros, '0', len);

    if (!(f->point && f->num_dot == 0 && n == 0))
    {
        write(1, num_str, num_len);
        (*len) += num_len;
    }

    if (f->minus)
        print_padding(padding, ' ', len);

    free(num_str);
    return (1);
}

int	ft_printunsigned(va_list ap, int *len, t_flags *f)
{
	unsigned int    n;
    char            *num_str;
    int             num_len;
    int             precision_zeros;
    int             total_len;
    int             padding;

    n = va_arg(ap, unsigned int);
    num_str = ft_utoa(n);
    num_len = ft_strlen(num_str);

    // 🔹 Regla especial: 0 con precision 0
    if (f->point && f->num_dot == 0 && n == 0)
        num_len = 0;

    // 🔹 PRECISION
    precision_zeros = 0;
    if (f->point && f->num_dot > num_len)
        precision_zeros = f->num_dot - num_len;

    total_len = num_len + precision_zeros;

    // 🔹 WIDTH
    padding = 0;
    if (f->num > total_len)
        padding = f->num - total_len;

    // 🔹 PRINT

    if (!f->minus)
    {
        if (f->zero && !f->point)
            print_padding(padding, '0', len);
        else
            print_padding(padding, ' ', len);
    }

    print_padding(precision_zeros, '0', len);

    if (!(f->point && f->num_dot == 0 && n == 0))
    {
        write(1, num_str, num_len);
        (*len) += num_len;
    }

    if (f->minus)
        print_padding(padding, ' ', len);

    free(num_str);
    return (1);
}
