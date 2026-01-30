#include "printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main()
{
	int a = 10;
	void *p;
	p = &a;
	//ft_printf("%s %c %i %x %X ", "hola", 'd', 10, 20, 10);
	ft_printf("%9s hola \"original\"\n", "pepe");
	printf("%9s hola \"original\"","pepe");
	return (0);
}