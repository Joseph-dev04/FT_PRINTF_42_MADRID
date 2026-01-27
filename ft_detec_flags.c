/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detec_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:44:47 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/27 12:40:24 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_size(char c)
{
	int	i;

	i = 0;
	while (i < ft_atoi(&c))
	{
		ft_putchar_fd('0',0);
		i++;
	}
	
}

void	ft_detec_flags(char const *str, int *i)
{
	while (*str && !ft_issapace(*str) && !ft_isalpha(*str))
	{
		if (*str == '0')
			ft_zero();
		if (*str == '.')
			ft_point();
		if (*str == '-')
			ft_tab();
		if (*str == '+')
			ft_plus();
		if (*str == '#')
			ft_hash();
		if (ft_isdigit(*str))
			ft_size(*str);
		*i++;
		str++;
	}
}
