/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detec_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:43:13 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/02 15:31:21 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
int	ft_detec_flags_plus(char const *str, int *i, va_list list, t_flags *flags)
{
	if (*str == 's')
		return (ft_printstring(list, i, flags));
	else if (*str == 'c')
		return (ft_printchar(list, i, flags));
	else if (*str == 'p')
		return (ft_printpointer(list, i, flags));
	else if (*str == 'd' || *str == 'i')
		return (ft_printinteger(list, i, flags));
	else if (*str == 'u')
		return (ft_printunsigned(list, i, flags));
	else if (*str == 'x' || *str == 'X')
		return (ft_printhexa(list, *str, flags));
	return (0);
}

void	ft_init_struct(t_flags *flags)
{
	flags->hash = 0;
	flags->minus = 0;
	flags->num = 0;
	flags->num_dot = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->point = 0;
}
/*
void	ft_show_struct(t_flags *flags)
{
	printf("\nzero:%i\n",flags->zero);
	printf("minus:%i\n",flags->minus);
	printf("plus:%i\n",flags->plus);
	printf("num:%i\n",flags->num);
	printf("num_dot:%i\n",flags->num_dot);
	printf("point:%i\n",flags->point);
	printf("hash:%i\n",flags->hash);
}*/

void	ft_detec_arguments(char const **str, int *i, va_list list, t_flags **flags)
{
	//ft_detec_flags(&str, i);
	ft_init_struct(*flags);
	while (!ft_detec_flags_plus(*str, i, list, *flags))
	{
		ft_detec_flags(*str, *flags);
		(*str)++;
	}
	//ft_detec_flags_plus(*str, i, list);
	(*str)++;
	//descomentar para el parseo
	//ft_show_struct(*flags);
}