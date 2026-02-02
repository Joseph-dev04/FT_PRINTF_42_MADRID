/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:47:45 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 14:55:17 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*str1;
	const char	*str2;

	str1 = (char *)dest;
	str2 = (const char *)src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
int main()
{
	char a[10] = "123456789";
	char b[10] = "acdefghij";
	char c[10] = "123456789";
	char d[10] = "acdefghij";
memcpy(a,b,2);
ft_memcpy(c,d,2);
 	printf("%s\n", a);
	printf("%s\n", c);
	return 0;
}*/