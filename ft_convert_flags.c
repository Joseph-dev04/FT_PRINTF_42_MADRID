/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:28:47 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/06 15:24:06 by jopajuel         ###   ########.fr       */
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
			if (flags->num)
				ft_zero(flags->num, ' ', i);
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
		*i += 1;
		ft_zero(flags->num - 1, ' ', i);
	}
	else if (flags->num > 1 && flags->zero)
	{
		ft_zero(flags->num, '0', i);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_zero(flags->num - 1, ' ', i);
		(*i)++;
		ft_putchar_fd(c, 1);
	}
}

void	ft_flags_int(t_flags *flags, char *str, int *i, int len)
{
	//ft_check_num(&str, len);
	if (flags->minus)
	{
		if (flags->point)
		{
			if (len < 0)
			{
				str++;
				if (flags->num_dot >= (int)ft_strlen(str))
				{
					ft_putchar_fd('-', 1);
					ft_zero((flags->num_dot - (int)ft_strlen(str)), '0', i);
					ft_putstr_fd(str, 1);
					ft_zero((flags->num - (flags->num_dot - (int)ft_strlen(str))), ' ', i);
					return ;
				}
				else
				{
					ft_putchar_fd('-', 1);
					ft_zero((flags->num_dot - (int)ft_strlen(str)), '0', i);
					ft_putstr_fd(str, 1);
					ft_zero(flags->num, ' ', i);
					return ;
				}
			}
			if (len == 0)
			{
				if (flags->num_dot > (int)ft_strlen(str))
					ft_zero(flags->num_dot, '0', i);
				ft_zero(flags->num - flags->num_dot, ' ', i);
				(*i)--;
				return ;
			}
		}
		else if (!flags->point && len == 0)
		{
			ft_putstr_fd(str, 1);
			flags->num--;
			ft_zero(flags->num, ' ', i);
			if (flags->plus && len >= 0)
				ft_putchar_fd('+', 1);
			return ;
		}
		if (flags->num_dot > (int)ft_strlen(str))
			ft_zero(flags->num_dot - (int)ft_strlen(str), '0', i);
		ft_putstr_fd(str, 1);
		if (flags->zero == 0 && !flags->point)
			ft_zero(flags->num, ' ', i);
		else if (flags->point && flags->zero == 0)
		{
			if (flags->num_dot > (int)ft_strlen(str))
				ft_zero(flags->num - (flags->num_dot - (int)ft_strlen(str)), ' ', i);
			else
				ft_zero(flags->num, ' ', i);
		}
	}
	else if ((flags->point && !flags->minus) && (flags->num_dot == 0 && len == 0))
	{
		ft_zero(flags->num, ' ', i);
		if (flags->plus && len >= 0)
			ft_putchar_fd('+', 1);
		(*i)--;
	}
	else if (flags->num >= (int)ft_strlen(str) && flags->zero)
	{
		if (flags->point)
		{
			if (flags->num_dot > (int)ft_strlen(str))
			{
				if (len < 0)
				{
					str++;
					ft_zero((flags->num - (flags->num_dot - (int)ft_strlen(str))), ' ', i);
					ft_putchar_fd('-', 1);
					ft_zero(flags->num_dot - (int)ft_strlen(str), '0', i);
					ft_putstr_fd(str, 1);
				}
				else
				{
					if (len == 0)
						ft_zero((flags->num - flags->num_dot), ' ', i);
					else
						ft_zero((flags->num - (flags->num_dot - (int)ft_strlen(str))), ' ', i);
					ft_zero(flags->num_dot - (int)ft_strlen(str), '0', i);
					ft_putstr_fd(str, 1);
				}
			}
			else
			{
				if (len < 0)
				{
					str++;
					if (flags->num_dot == (int)ft_strlen(str) + 1)
					{
						ft_zero(--flags->num, ' ', i);
						ft_putchar_fd('-', 1);
						ft_zero(1, '0', i);
						ft_putstr_fd(str, 1);
					}
					else
					{
						ft_zero(flags->num, ' ', i);
						ft_putchar_fd('-', 1);
						ft_putstr_fd(str, 1);
					}
				}
				else
				{
					ft_zero(flags->num, ' ', i);
					ft_putstr_fd(str, 1);
				}
			}
		}
		else
		{
			ft_check_num(&str, len);
			if (flags->plus)
				ft_putchar_fd('+', 1);
			if (len == 0)
				flags->num--;
			ft_zero(flags->num, '0', i);
			ft_putstr_fd(str, 1);
		}
	}
	else if (flags->point && flags->num_dot < flags->num)
	{
		if (len < 0)
		{
			str++;
			if (flags->num_dot >= (int)ft_strlen(str))
			{
				if (flags->num_dot == (int)ft_strlen(str)+1)
				{
					if (flags->num > flags->num_dot)
					{
						flags->num--;
						ft_zero(flags->num, ' ', i);
						ft_putchar_fd('-', 1);
						ft_zero(1, '0', i);
						ft_putstr_fd(str, 1);
					}
					else
					{
						if (len < 0)
							ft_check_num(&str, len);
						ft_zero(1, '0', i);
						ft_putstr_fd(str, 1);
					}
				}
				else
				{
					ft_zero((flags->num - (flags->num_dot - (int)ft_strlen(str))), ' ', i);
					ft_putchar_fd('-', 1);
					ft_zero((flags->num_dot - (int)ft_strlen(str)), '0', i);
					ft_putstr_fd(str, 1);
				}
			}
			else
			{
				if (flags->num_dot < (int)ft_strlen(str))
				{
					ft_zero((flags->num ), ' ', i);
					ft_putchar_fd('-', 1);
					ft_zero((flags->num_dot - (int)ft_strlen(str)), '0', i);
					ft_putstr_fd(str, 1);
				}
				else
				{
					ft_zero((flags->num - (flags->num_dot - (int)ft_strlen(str))), ' ', i);
					ft_putchar_fd('-', 1);
					ft_zero((flags->num_dot - (int)ft_strlen(str)), '0', i);
					ft_putstr_fd(str, 1);
				}
			}
		}
		else
		{
			if (len == 0)
				flags->num--;
			if (flags->num_dot < (int)ft_strlen(str))
				ft_zero(flags->num, ' ', i);
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
		if (len == 0)
			flags->num--;
		ft_zero(flags->num, ' ', i);
		if (flags->plus && len >= 0)
			ft_putchar_fd('+', 1);
		if (flags->num_dot == (int)ft_strlen(str))
		{
			if (len < 0)
			{
				ft_check_num(&str, len);
				ft_zero(1, '0', i);
			}
		}
		ft_putstr_fd(str, 1);
	}
}

void	ft_flags_unint(t_flags *flags, char *str, int *i, int len)
{
	if (flags->minus)
	{//printf("*%i %i*", flags->num, flags->num_dot);
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
				
				if (flags->num < (int)ft_strlen(str))
				{
					//(*i)++;
					if (flags->zero == 0)
					ft_zero(flags->num, ' ', i);
					return ;
				}
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
			else if (flags->num_dot < (int)ft_strlen(str))
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
int	ft_lenhexaminus(char *str, unsigned int i, int len)
{
	if (i < 16)
	{
		len++;
		//ft_putchar_fd(str[i], 1);
	}else{
		return (1 + ft_lenhexaminus(str, i / 16, len));}
		return (1);
		//ft_putchar_fd(str[i % 16], 1);
}
void	ft_flags_hexa(t_flags *flags, unsigned int i, char *str, int *len)
{
	if (flags->minus)
	{//printf("*%i %i %i*", flags->num, flags->num_dot, ft_lenhexa(i));
		if (flags->hash)
			ft_putstr_fd("0x", 1);
		if (flags->num >= flags->num_dot && flags->num_dot > ft_lenhexa(i))
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

				ft_zero(flags->num_dot - ft_lenhexaminus(str,i, 0), '0', len);
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
	{//printf("*%i %i*", flags->num, flags->num_dot);
		if (flags->zero)
		{
			if (flags->num > flags->num_dot && flags->num > ft_lenhexa(i) && flags->num_dot > ft_lenhexa(i))
			{
				if (i == 0)
				{
					ft_zero(flags->num - (flags->num_dot - ft_lenhexa(i)), ' ', len);
					ft_zero(flags->num_dot - ft_lenhexa(i), '0', len);
				}
				else
				{
					ft_zero(flags->num - (flags->num_dot - ft_lenhexa(i)), ' ', len);
					ft_zero(flags->num_dot - ft_lenhexa(i), '0', len);
					ft_hexa(str, i, len);
				}
			}
			else if (flags->num > flags->num_dot && flags->num > ft_lenhexa(i) && flags->num_dot < ft_lenhexa(i))
			{
				ft_zero(flags->num, ' ', len);
				ft_zero(flags->num_dot - ft_lenhexa(i), '0', len);
				ft_hexa(str, i, len);
			}
			else if (flags->num < flags->num_dot && flags->num_dot > ft_lenhexa(i))
			{
				if (flags->num + ft_lenhexa(i) > flags->num_dot)
					ft_zero((flags->num) - (flags->num_dot - ft_lenhexa(i)), ' ', len);
				ft_zero(flags->num_dot - ft_lenhexa(i), '0', len);
				ft_hexa(str, i, len);
			}
			else
			{
				ft_zero(flags->num, ' ', len);
				ft_hexa(str, i, len);
			}
		}
		else if (flags->num_dot > ft_lenhexa(i) && flags->num_dot > flags->num)
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
			else if (flags->num_dot == ft_lenhexa(i))
			{
				ft_zero(ft_lenhexa(i), ' ', len);
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
			if (flags->num && !flags->num_dot)
			{
				if (flags->num < ft_lenhexa(i))
				{
					ft_hexa(str, i, len);
				}
				else if (flags->num > ft_lenhexaminus(str,i,0))
				{
					ft_zero(flags->num, '0', len);
					ft_hexa(str, i, len);
				}
				else{
					ft_zero((flags->num + ft_lenhexa(i)) - ft_lenhexaminus(str, i ,0), '0', len);
					ft_hexa(str, i, len);
				}
			}
			else
			{
				ft_zero(flags->num, '0', len);
				ft_hexa(str, i, len);
			}
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
