/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:49:37 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 14:51:21 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
/*
void	clear(void *t)
{
	free(t);
}
int main()
{
	t_list *p = ft_lstnew(ft_strdup("0")); 
    
    ft_lstdelone(p, clear);
	if(!p)
	{
		printf("limpio");
	}
	return 0;
}*/