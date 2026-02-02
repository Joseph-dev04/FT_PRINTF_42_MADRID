/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:21:30 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 14:04:53 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("doc.txt", O_WRONLY | O_CREAT | O_APPEND,0644);
	if (fd < 0)
	{
		printf("error al abrir el archivo");
	}
	ft_putendl_fd("hello world",fd);
	ft_putendl_fd("hello ",fd);
	return 0;
}*/