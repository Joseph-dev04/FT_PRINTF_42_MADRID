/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:13:45 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 14:06:38 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	if ((unsigned char)str[i] != (unsigned char)c)
		return (NULL);
	return (str + i);
}
/*
#include <string.h>
int	main()
{
	char a[10] = "123456789";
	printf("%s\n", strchr(a,'5'));
	printf("%s", ft_strchr(a,'5'));
	return 0;
}*/