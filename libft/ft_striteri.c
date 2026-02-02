/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:06:28 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 14:07:19 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void pepe(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = '1';
}

int main()
{
	char a[10] = "abcdefg";
	ft_striteri(a, pepe);
	printf("%s\n", a);
	return (0);
}*/