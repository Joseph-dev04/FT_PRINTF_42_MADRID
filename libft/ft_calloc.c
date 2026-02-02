/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:05:39 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 12:22:00 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
/*
int main()
{
	char *a = (char *)calloc(5,0);
	char *b = (char *)ft_calloc(5,0);
	printf("%s\n",a);
	printf("%s\n",b);
	int i = 0;
	while(i < 5)
	{
		printf("real %d\n",a[i]);
		printf("copia %d\n",b[i]);
		i++;
	}
	free(a);
	free(b);
	return (0);
}
*/