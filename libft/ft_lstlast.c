/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:21:45 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 15:37:54 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	t_list *aux = ft_lstlast(p);
	printf("%s\n", (char *)aux->content);
	return 0;
}*/