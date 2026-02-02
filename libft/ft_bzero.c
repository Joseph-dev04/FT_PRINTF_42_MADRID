/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:46:01 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 13:48:40 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
/*
#include <strings.h>
int main()
{	
	char a[15] = "123456789abcdef";
	char b[15] = "123456789abcdef";
	size_t	n;
	int s1 = 300;
	int s2 = 300;
	n = 10;

		ft_bzero(&s1, 1);
		bzero(&s2, 1);
		printf("%i\n",s1);
		printf("%i\n",s2);
		int i = 0;
		while(i<15)
		{
			printf("%c", a[i]);
			i++;	
		}
		printf("\n");
		i = 0;
		while(i<15)
		{
			printf("%c", b[i]);
			i++;	
		}
		
		//printf("%s\n",s);
		return 0;
}*/