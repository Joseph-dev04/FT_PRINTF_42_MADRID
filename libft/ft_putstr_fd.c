/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:10:41 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 14:42:18 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("doc.txt", O_APPEND | O_CREAT | O_RDWR,0644);
	if (fd < 0)
	{
		printf("error al abrir el archivo");
	}
	ft_putstr_fd("hello world",fd);
	return 0;
}*/