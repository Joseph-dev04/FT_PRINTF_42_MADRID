/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:45:17 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 13:57:19 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
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

void	ft_value(char *str, int i, long int nb)
{
	while (i >= 0)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			sign;
	int			i;

	i = ft_count(n);
	nb = n;
	sign = 1;
	if (nb < 0)
	{
		sign *= -1;
		nb *= -1;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	ft_value(str, i, nb);
	if (sign < 0)
		str[0] = '-';
	return (str);
}
/*
int main()
{
	char *str;
	int i;

	i = 0;
	str = ft_itoa(-21);
	while (str[i])
	{
		printf("%c\n", str[i]);
		i++;
	}
	free(str);
	return 0;
}*/