/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:08:40 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 13:58:28 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*temp;

	aux = *lst;
	temp = aux;
	while (aux)
	{
		aux = temp->next;
		del(temp->content);
		free(temp);
		temp = aux;
	}
	*lst = NULL;
}
/*
void	clear(void *t)
{
	free(t);
}
int main()
{
	t_list *p = ft_lstnew(ft_strdup("0")); 
    p->next = ft_lstnew(ft_strdup("1"));
	p->next->next = ft_lstnew(ft_strdup("2"));
    ft_lstclear(&p, clear);

	return 0;
}*/