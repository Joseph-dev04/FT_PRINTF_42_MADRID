/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:28:21 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 15:04:04 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char pepe(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (ft_toupper(c));
	return (ft_tolower(c));
}

int main()
{
	char a[10] = "abcdefg";
	char *s = ft_strmapi(a, pepe);
	printf("%s\n", s);
	free(s);
	return (0);
}*/