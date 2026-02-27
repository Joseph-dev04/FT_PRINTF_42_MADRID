/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:40:28 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/27 11:16:39 by jopajuel         ###   ########.fr       */
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
