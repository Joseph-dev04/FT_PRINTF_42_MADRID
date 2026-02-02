/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:14:40 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 15:04:28 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				count;
	unsigned char	c_unsigned;

	c_unsigned = c;
	if (c_unsigned == '\0')
		return ((char *)&str[ft_strlen(str)]);
	count = ft_strlen(str) - 1;
	if (count < 0)
		return (NULL);
	while (count >= 0)
	{
		if (str[count] == c_unsigned)
		{
			return ((char *)&str[count]);
		}
		count--;
	}
	return (NULL);
}
/*
#include <string.h>
int main()
{
	char a[10] = "123456189";
	printf("%s\n", strrchr(a, '1'));
	printf("%s", ft_strrchr(a,'1'));
	return 0;
}*/