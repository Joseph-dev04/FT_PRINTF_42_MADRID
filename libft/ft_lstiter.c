/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:33:06 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 14:44:13 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	ft_one(void *content)
{
	char *s = (char *)content;
	s[0] = '1';
}
int main()
{
	t_list *p = ft_lstnew(ft_strdup("0")); 
    p->next = ft_lstnew(ft_strdup("1")); 
    p->next->next = ft_lstnew(ft_strdup("2"));
	ft_lstiter(p,ft_one);
	while (p)
	{
		printf("%s\n", (char *)p->content);
		p = p->next;
	}
	return 0;
}*/