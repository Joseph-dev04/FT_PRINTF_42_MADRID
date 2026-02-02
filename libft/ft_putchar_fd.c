/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:55:09 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/22 14:04:38 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("doc.txt",O_RDWR, O_APPEND, O_CREAT);
	if (fd < 0)
	{
		printf("error en lectura");
	}
	ft_putchar_fd('d',fd);
	return 0;
}*/