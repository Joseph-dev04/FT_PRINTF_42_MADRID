/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:34:56 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 14:53:03 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}
/*
int main()
{
	t_list	*p;
	t_list	*aux;
	char a[20] = "123456789";
	char b[20] = "abcdefghi";
	p = ft_lstnew(a);
	if (!p)
		return 0;
	p->next = ft_lstnew(b);
	aux = p;
	while (aux)
	{
		printf("%s\n", (char *)aux->content);
		aux = aux->next;
	}
	return 0;
}*/