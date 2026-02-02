/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:19:48 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 13:24:09 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	z;

	if (!s)
		return (NULL);
	i = 0;
	z = ft_strlen((char *)s);
	if (len > z)
		len = z;
	if (start >= z)
		return (ft_strdup(""));
	if (len > z - start)
		len = z - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i++ < start)
		s++;
	ft_strlcpy(str, s, len + 1);
	return (str);
}
/*
int main()
{
	char a[10] = "123456789";
	char *b;
	b = ft_substr(a,2,8);
	printf("%s\n", b);
	free(b);
	return 0;
}*/