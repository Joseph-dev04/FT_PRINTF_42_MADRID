/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:37:28 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/04 11:48:10 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstlast_local(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	last = ft_lstlast_local(last);
	last->next = new;
}
/*
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst && new)
	{
		aux = *lst;
		while (aux->next)
		{
			aux = aux->next;
		}
		aux->next = new;
	}
}*/
/*
int main()
{
	char a[2] = "0";
	char b[2] = "1";
	char c[2] = "2";
	char d[2] = "3";
	char e[2] = "4";
	t_list *p = ft_lstnew(a);
	p->next = ft_lstnew(b);
	p->next->next = ft_lstnew(c);
	p->next->next->next = ft_lstnew(d);
	ft_lstadd_back(&p, ft_lstnew(e));
	printf("%s\n", (char *)ft_lstlast(p)->content);
	return 0;
}*/