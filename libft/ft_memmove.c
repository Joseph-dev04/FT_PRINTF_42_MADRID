/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:02:23 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 14:22:31 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str, const void *src, size_t n)
{
	size_t			i;
	char			*str1;
	char			*str2;

	str1 = (char *)str;
	str2 = (char *)src;
	if (str1 == NULL && str2 == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src > str && i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	while (src <= str && n > 0)
	{
		str1[n - 1] = str2[n - 1];
		n--;
	}
	return (str);
}
/*
#include <string.h>
int main()
{
	char a[20] = "ABCDE";
	char b[20] = "ABCDE";
	ft_memmove(b+6,b,5);
	memmove(a+6,a,5);
	printf("%s\n", a);
	printf("%s",a);
	return 0;
}*/