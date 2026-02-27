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
	char	c;
	int		padding;

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
