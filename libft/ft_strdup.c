/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:22:58 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 15:02:21 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*a;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	a = malloc(sizeof(char) * len + 1);
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
/*
#include <string.h>
int main()
{
	char *a = "hola";
	char *b = "hola";
	printf("%p %p\n", a, b);
	printf("%p\n",strdup(a));
	printf("%p\n",ft_strdup(b));
	return (0);
}*/