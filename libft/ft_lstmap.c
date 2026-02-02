/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:55:22 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 13:59:44 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
void	ft_clear(void *contet)
{
	free(contet);
}
void	*transfor(void *content)
{
	char *new = (char *)content;
	new[0] = '0';
	return content;
}
int main()
{
	t_list *p = ft_lstnew(ft_strdup("0")); 
	p->next = ft_lstnew(ft_strdup("1")); 
	p->next->next = ft_lstnew(ft_strdup("2"));
	t_list *s = ft_lstmap(p,transfor,ft_clear);
	while(s)
	{
		printf("%s\n",(char *)s->content);
		s = s->next;
	}
	return 0;
}*/