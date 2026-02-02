/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:56:15 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 13:58:17 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//[2] -> [0][1]   lst -> [0][1] | lst ->[2]->[0][1]
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*

int main()
{
	char a[2] = "0";
	char b[2] = "1";
	char c[2] = "2";
	char d[2] = "3";
	char e[2] = "4";
	t_list *p;
	t_list	*new;
	p = ft_lstnew(a);
	p->next = ft_lstnew(b);
	new = ft_lstnew(c);
	ft_lstadd_front(&p, new);
	while(p)
	{
		printf("%s\n",(char *)p->content);
		p = p->next;
	}
	free(p);
	return 0;
}*/