/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_plus_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:46:03 by jopajuel          #+#    #+#             */
/*   Updated: 2026/03/02 12:58:01 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_case_null(t_flags *f, int print_len)
{
	if (f->point && f->num_dot > 5)
		write(1, "(null)", 6);
	else if (!f->point)
		write(1, "(null)", 6);
	else
		write(1, " ", print_len);
}

void	print_padding(int n, char c, int *len)
{
	while (n-- > 0)
	{
		write(1, &c, 1);
		(*len)++;
	}
}
