/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:44:21 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 14:41:16 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)str;
	while (i < n)
	{
		dst[i] = c;
		i++;
	}
	return (str);
}
/*
#include <string.h>
int main()
{
	char	a[10] = "123456789";
	memset(a,'x',8);
		printf("%s\n", a);
	ft_memset(a,'z',8);
		printf("%s\n", a);
		return 0;
}*/