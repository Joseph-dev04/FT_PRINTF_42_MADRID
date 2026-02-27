/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:34:19 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/27 11:18:49 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenun(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			i++;
	}
	return (++i);
}

char	*ft_utoa(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	i = ft_lenun(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}

void	ft_check_num(char **str, int len)
{
	if (len < 0)
	{
		ft_putchar_fd('-', 1);
		(*str)++;
	}
}

static int	ft_numlen_base(unsigned int n, int base_len)
{
	int	len;

	len = 1;
	while (n >= (unsigned int)base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	char			*result;
	int				base_len;
	int				len;

	base_len = 0;
	while (base[base_len])
		base_len++;

	len = ft_numlen_base(n, base_len);

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
int ft_printhexa(va_list ap,char uppercase, int *len , t_flags *f)
{
    unsigned int    n;
    char            *num_str;
    int             num_len;
    int             precision_zeros;
    int             total_len;
    int             padding;
    int             prefix_len;
    char            *base;

    n = va_arg(ap, unsigned int);

	if (uppercase == 'x')
		base = "0123456789abcdef";
	else if (uppercase == 'X')
		base = "0123456789ABCDEF";


    num_str = ft_utoa_base(n, base);
    num_len = ft_strlen(num_str);

    // 🔹 Regla especial: 0 con precision 0
    if (f->point && f->num_dot == 0 && n == 0)
        num_len = 0;

    // 🔹 PREFIJO (#)
    prefix_len = 0;
    if (f->hash && n != 0)
        prefix_len = 2;

    // 🔹 PRECISION
    precision_zeros = 0;
    if (f->point && f->num_dot > num_len)
        precision_zeros = f->num_dot - num_len;

    total_len = num_len + precision_zeros + prefix_len;

    // 🔹 WIDTH
    padding = 0;
    if (f->num > total_len)
        padding = f->num - total_len;

    // 🔹 PRINT

    if (!f->minus)
    {
        if (f->zero && !f->point)
        {
            // prefijo va antes de los ceros
            if (prefix_len)
            {
                if (uppercase == 'x')
					write(1,"0x", 2);
				else if (uppercase == 'X')
        			write(1, "0X", 2);
                (*len) += 2;
                prefix_len = 0;
            }
            print_padding(padding, '0', len);
        }
        else
            print_padding(padding, ' ', len);
    }

    // prefijo si aún no se imprimió
    if (prefix_len)
    {
		if (uppercase == 'x')
			write(1,"0x", 2);
		else if (uppercase == 'X')
        	write(1, "0X", 2);
        (*len) += 2;
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

