/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 10:28:11 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/27 11:13:58 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
