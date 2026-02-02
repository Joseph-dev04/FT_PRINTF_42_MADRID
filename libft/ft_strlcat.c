/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:05:35 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 15:03:38 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;
	size_t	lensrc;

	i = 0;
	lendest = ft_strlen((const char *)dst);
	if (size < lendest)
		lensrc = ft_strlen(src) + size;
	else
	{
		lensrc = lendest + ft_strlen(src);
		while (lendest + i + 1 < size && src[i])
		{
			dst[i + lendest] = src[i];
			i++;
		}
		dst[i + lendest] = '\0';
	}
	return (lensrc);
}
/*
#include <bsd/string.h>
int	main()
{
	char a[20] = "";
	char b[10] = "123";
	char a1[20] = "";
	char b1[10] = "123";
	printf("copiados: %zu %s\n",strlcat(a,b,10), a);
	printf("copiados: %zu %s\n",ft_strlcat(a1,b1,10), a1);
	int i = 0;
	while (a1[i])
	{
		printf("posicion%i: %c\n",i,a[i]);
		printf("posicion%i: %c\n",i,a1[i]);
		i++;
	}
	return 0;
}*/