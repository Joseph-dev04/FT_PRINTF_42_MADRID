/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:08:57 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 14:00:05 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		i;

	i = 0;
	if (!lst)
		return (i);
	aux = lst;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}
/*
int main()
{
	char a[2] = "0";
	char b[2] = "1";
	char c[2] = "2";
	char d[2] = "3";
	t_list *p = ft_lstnew(a);
	p->next = ft_lstnew(b);
	p->next->next = ft_lstnew(c);
	p->next->next->next = ft_lstnew(d);
	printf("%i\n", ft_lstsize(p));
	return 0;
}*/