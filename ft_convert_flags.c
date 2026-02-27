/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:28:47 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/27 10:25:06 by jopajuel         ###   ########.fr       */
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

void	ft_flags_unint(t_flags *flags, char *str, int *i, int len)
{
	if (flags->minus)
	{
		if (flags->num > flags->num_dot && flags->num_dot > (int)ft_strlen(str))
		{
			ft_zero(flags->num_dot - (int)ft_strlen(str), '0', i);
			ft_putstr_fd(str, 1);
			ft_zero(flags->num - (flags->num_dot - (int)ft_strlen(str)), ' ', i);
		}
		else if (flags->num < flags->num_dot && flags->num_dot > (int)ft_strlen(str))
		{
			ft_zero(flags->num_dot - (int)ft_strlen(str), '0', i);
			ft_putstr_fd(str, 1);
		}
		else
		{
			if (len == 0 && flags->point)
			{
				flags->num++;
				ft_zero(flags->num, ' ', i);
				(*i)--;

			}else
			{
				ft_putstr_fd(str, 1);
				*i = 1;
				if (flags->zero == 0)
					ft_zero(flags->num, ' ', i);
			}
		}
	}
	else if (flags->point)
	{
		if (flags->num)
		{
			if (flags->num > flags->num_dot && flags->num_dot > (int)ft_strlen(str))
			{
				ft_zero(flags->num - (flags->num_dot - (int)ft_strlen(str)), ' ', i);
				ft_zero(flags->num_dot - (int)ft_strlen(str), '0', i);
				ft_putstr_fd(str, 1);
			}
			else if (flags->num > flags->num_dot && flags->num_dot < (int)ft_strlen(str))
			{
				if (len == 0)
				{
					flags->num++;
					ft_zero(flags->num, ' ', i);
					ft_zero(flags->num_dot, '0', i);
					(*i)--;
				}
				else
				{
					ft_zero(flags->num, ' ', i);
					ft_zero(flags->num_dot - (int)ft_strlen(str), '0', i);
					ft_putstr_fd(str, 1);
				}
			}
			else if (flags->num < flags->num_dot && flags->num_dot > (int)ft_strlen(str))
			{
				ft_zero(flags->num_dot - (int)ft_strlen(str), '0', i);
				ft_putstr_fd(str, 1);
			}
			else if (flags->num == (flags->num_dot - (int)ft_strlen(str)) && flags->num_dot < (int)ft_strlen(str))
			{
				ft_putstr_fd(str, 1);
			}
		}
		else if (flags->num_dot > (int)ft_strlen(str))
		{
			ft_zero(flags->num_dot - (int)ft_strlen(str), '0', i);
			ft_putstr_fd(str, 1);
		}
		else if (flags->num_dot <= (int)ft_strlen(str))
		{
			if (len == 0)
			{
				(*i)--;
			}else
				ft_putstr_fd(str, 1);
		}
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
		if (flags->num > flags->num_dot && flags->num_dot > ft_lenhexa(i))
		{
			if (i == 0)
			{
				ft_zero(flags->num_dot - ft_lenhexa(i), '0', len);
				ft_zero(flags->num - (flags->num_dot - ft_lenhexa(i)), ' ', len);
			}
			else
			{
				ft_zero(flags->num_dot - ft_lenhexa(i), '0', len);
				ft_hexa(str, i, len);
				ft_zero(flags->num - (flags->num_dot - ft_lenhexa(i)), ' ', len);
			}
		}
		else if (flags->num < flags->num_dot && flags->num_dot > ft_lenhexa(i))
		{
			ft_zero(flags->num_dot - ft_lenhexa(i), '0', len);
			ft_hexa(str, i, len);
		}
		else if (flags->num > flags->num_dot && flags->num_dot == ft_lenhexa(i))
		{
			if (i == 0)
			{
				if (!flags->point)
				{
					ft_hexa(str, i, len);
					flags->num--;
					ft_zero(flags->num, ' ', len);
				}
				else
					ft_zero(flags->num, ' ', len);
			}else{
			ft_zero(flags->num, ' ', len);
			}
		}
		else if (flags->zero == 0)
		{
			ft_hexa(str, i, len);
			if (i == 0)
				flags->num--;
			ft_zero(flags->num, ' ', len);
		}
	}
	else if(flags->point)
	{
		if (flags->num_dot > ft_lenhexa(i) && flags->num_dot > flags->num)
		{
			if (i == 0)
			{
				ft_zero(flags->num_dot, '0', len);
			}
			else
			{
				ft_zero(flags->num_dot - ft_lenhexa(i), '0', len);
				ft_hexa(str, i, len);
			}
		}
		else if (flags->num > flags->num_dot)
		{
			if (i == 0)
			{
				ft_zero(flags->num - flags->num_dot , ' ', len);
				ft_zero(flags->num_dot, '0', len);
			}
			else if (flags->num_dot < ft_lenhexa(i))
			{
				ft_zero(flags->num, ' ', len);
				ft_hexa(str, i, len);
			}
			else
			{
				ft_zero(flags->num - (flags->num_dot - ft_lenhexa(i)), ' ', len);
				ft_zero(flags->num_dot - ft_lenhexa(i), '0', len);
				ft_hexa(str, i, len);
			}
		}
		else
		{
			if (i == 0)
			{
				ft_zero(flags->num_dot, '0', len);
			}
			else
			{
				ft_hexa(str, i, len);
			}
		}
	}
	else if (flags->zero)
	{
		if (i == 0)
		{
			ft_zero(flags->num, '0', len);
		}
		else
		{
			if (flags->hash)
				ft_putstr_fd("0x", 1);
			ft_zero(flags->num, '0', len);
			ft_hexa(str, i, len);
		}
	}
	else
	{
		if (flags->num && i == 0)
		{
				flags->num--;
				ft_zero(flags->num, ' ', len);
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
}
