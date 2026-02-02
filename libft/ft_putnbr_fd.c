/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:33:41 by jopajuel          #+#    #+#             */
/*   Updated: 2026/01/23 14:53:16 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	aux;

	aux = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		aux = (unsigned int)(n * -1);
	}
	if (aux > 9)
		ft_putnbr_fd(aux / 10, fd);
	ft_putchar_fd((char)(aux % 10 + '0'), fd);
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
	ft_putnbr_fd(123, fd);
	return 0;
}*/