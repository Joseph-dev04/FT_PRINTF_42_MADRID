/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:04:08 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 15:03:53 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	count = ft_strlen(src);
	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
/*
#include <bsd/string.h>

int main()
{
	char a[10] = "1234567";
	char b[10] = "1234567";
	printf("%lu %s\n",strlcpy(a,"abcdefgh",10), a);
	printf("%lu %s\n", ft_strlcpy(b,"abcdefgh", 10), b);
	printf("%c", a[4]);
	return 0;
}*/