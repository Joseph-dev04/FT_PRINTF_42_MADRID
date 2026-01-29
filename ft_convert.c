/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:40:28 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/29 12:46:51 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

void	ft_printstring(va_list list, int *len)
{
	char	*src;
	int	i;

	i = 0;
	src = va_arg(list, char *);
	while (src[i])
	{
		ft_putchar_fd(src[i], 0);
		i++;
	}
	len += i;
}

void	ft_printchar(va_list list, int *len)
{
	ft_putchar_fd(va_arg(list, int), 0);
	len++;
}
void	ft_printpointer(va_list list, int *len)
{
	void	*p;
	char	*str;
	
	p = va_arg(list, void *);
	ft_putstr_fd("0x0",0);
	len += 3;
	str = (char *)p + 3;
	while (*str)
	{
		ft_putchar_fd(*str,0);
		str++;
		len++;
	}
	
}

void	ft_printinteger(va_list list, int *len)
{
	int	i;
	char	*str;

	i = va_arg(list, int);
	str = ft_itoa(i);
	len += ft_strlen(str);
	ft_putstr_fd(str,0);
	free(str);
}

void	ft_printunsigned(va_list list, int *len)
{
	int i;
	char	*str;

	i = va_arg(list, unsigned int);
	str = ft_itoa(i);
	len += ft_strlen(str);
	ft_putstr_fd(str,0);
	free(str);
}

int	ft_hexa(char *str, int i)
{
	int	j;

	j = 0;
	if (i < 16)
	{
		ft_putchar_fd(str[i], 0);
		j++;
	}
	else
	{
		ft_hexa(str, i / 16);
		ft_putchar_fd(str[i % 16], 0);
		j++;		
	}
	return (j);
}

void	ft_printhexa(va_list list, char c)
{
	int	num;
	char *str;
	
	num = va_arg(list, int);
	if (c == 'x')
	{
		str = "012346789abcdef";
		ft_hexa(str, num);
	}
	else
	{
		str = "012346789ABCDEF";
		ft_hexa(str, num);
	}
	
}