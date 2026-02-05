/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:28:47 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/04 18:07:12 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_flags_caracters(t_flags *flags, char *src, int *i)
{
	if (flags->minus)
	{
		if (!src)
		{
			ft_putstr_fd("(null)", 1);
			(*i) += 6;
		}
		else
		{
			if (flags->num_dot && flags->num_dot <= (int)ft_strlen(src))
			{
				while (flags->num_dot--)
				{
					ft_putchar_fd(src[flags->iter++], 1);
					(*i)++;
				}
			}
			else
			{
				(*i) += ft_strlen(src);
				ft_putstr_fd(src, 1);
			}
		}
		if (flags->zero == 0)
			ft_zero(flags->num, ' ', i);
	}
	else if (flags->num  && flags->zero)
	{
		ft_zero(flags->num, '0', i);
		if (!src)
		{
			ft_putstr_fd("(null)", 1);
			(*i) += 6;
		}
		else
			ft_putstr_fd(src, 1);
	}
	else if (flags->point)
	{
		if (!src)
		{
			//printf("f%i %if", flags->num, flags->num_dot);
			if (flags->num_dot && flags->num_dot >= 6)
			{
				ft_putstr_fd("(null)", 1);
				(*i) += 6;
			}
			ft_putstr_fd("", 1);
		}
		else
		{
			if (flags->num)
			{
				ft_zero(flags->num, ' ', i);
			}
			if (flags->num_dot <= (int)ft_strlen(src))
			{
				while (flags->num_dot--)
				{
					ft_putchar_fd(src[flags->iter++], 1);
					(*i)++;
				}
			}
			else
			{
				ft_putstr_fd(src, 1);
					(*i) += ft_strlen(src);
			}
		}
	}
	else
	{
		ft_zero(flags->num, ' ', i);
		if (!src)
		{
			ft_putstr_fd("(null)", 1);
			(*i) += 6;
		}
		else
		{
			//if (flags->num < (int)ft_strlen(src))
			(*i) += ft_strlen(src);
			ft_putstr_fd(src, 1);
		}
	}
}

void	ft_flags_trings(t_flags *flags, char c, int *i)
{
	if (flags->minus)
	{
		ft_putchar_fd(c, 1);
		*i = 1;
		if (flags->zero == 1)
			ft_zero(flags->num, ' ', i);
	}
	else if (flags->num > 1 && flags->zero)
	{
		ft_zero(flags->num, '0', i);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_zero(flags->num, ' ', i);
		ft_putchar_fd(c, 1);
	}
}

void	ft_flags_int(t_flags *flags, char *str, int *i, int len)
{
	//ft_check_num(&str, len);
	if (flags->minus)
	{
		ft_putstr_fd(str, 1);
		if (flags->zero == 0)
			ft_zero(flags->num, ' ', i);
	}
	else if (flags->num >= (int)ft_strlen(str) && flags->zero)
	{
		ft_check_num(&str, len);
		if (flags->plus)
			ft_putchar_fd('+', 1);
		ft_zero(flags->num, '0', i);
		ft_putstr_fd(str, 1);
	}
	else if (flags->point && flags->num_dot < flags->num)
	{
		if (len < 0)
		{
			str++;
			ft_zero((flags->num - (flags->num_dot - (int)ft_strlen(str))), ' ', i);
			ft_putchar_fd('-', 1);
			ft_zero((flags->num_dot - (int)ft_strlen(str)), '0', i);
			ft_putstr_fd(str, 1);
		}
		else
		{
			if (flags->num_dot < (int)ft_strlen(str))
				ft_zero((flags->num - ((int)ft_strlen(str) - flags->num_dot)), ' ', i);
			else
				ft_zero((flags->num - (flags->num_dot - (int)ft_strlen(str))), ' ', i);
			ft_zero((flags->num_dot - (int)ft_strlen(str)), '0', i);
			ft_putstr_fd(str, 1);
		}
	}
	else if (flags->point && flags->num_dot > (int)ft_strlen(str))
	{
		if (len < 0)
		{
			ft_check_num(&str, len);
			ft_zero((flags->num_dot - (int)ft_strlen(str)), '0', i);
			ft_putstr_fd(str, 1);
		}
		else
		{
			ft_zero((flags->num_dot - (int)ft_strlen(str)), '0', i);
			ft_putstr_fd(str, 1);
		}
	}
	
	else
	{
		//ft_check_num(&str, len);
		ft_zero(flags->num, ' ', i);
		if (flags->plus && len >= 0)
			ft_putchar_fd('+', 1);
		ft_putstr_fd(str, 1);
	}
}

void	ft_flags_unint(t_flags *flags, char *str, int *i, int len)
{
	if (flags->minus)
	{
		ft_putstr_fd(str, 1);
		*i = 1;
		if (flags->zero == 0)
			ft_zero(flags->num, ' ', i);
	}
	else if (flags->num >= (int)ft_strlen(str) && flags->zero)
	{
		if (flags->plus)
			ft_putchar_fd('+', 1);
		ft_zero(flags->num, '0', i);
		ft_putstr_fd(str, 1);
	}
	else
	{
		ft_zero(flags->num, ' ', i);
		if (flags->plus && len >= 0)
			ft_putchar_fd('+', 1);
		ft_putstr_fd(str, 1);
	}
}

void	ft_flags_hexa(t_flags *flags, unsigned int i, char *str, int *len)
{
	if (flags->minus)
	{
		if (flags->hash)
			ft_putstr_fd("0x", 1);
		ft_hexa(str, i, len);
		if (flags->zero == 0)
			ft_zero(flags->num, ' ', len);
	}
	else if (flags->zero)
	{
		if (flags->hash)
			ft_putstr_fd("0x", 1);
		ft_zero(flags->num, '0', len);
		ft_hexa(str, i, len);
	}
	else
	{
		ft_zero(flags->num, ' ', len);
		if (flags->hash)
			ft_putstr_fd("0x", 1);
		ft_hexa(str, i, len);
	}
}
