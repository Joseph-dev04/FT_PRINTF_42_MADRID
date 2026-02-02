/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:16:52 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 12:16:53 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p;

	i = 0;
	p = (const unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
int main()
{
	size_t b = 10;
	char a[10] = "1234a6789a";
	void *p = memchr(&a, 'a', sizeof(char)*1);
	void *s = memchr(&a, 'a', sizeof(char)*1);
	printf("%p\n", p);
	printf("%p\n", s);
	return 0;
}*/