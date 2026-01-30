#include "printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main()
{
	int a = 10;
	void *p;
	p = &a;
	//ft_printf("%s %c %i %x %X ", "hola", 'd', 10, 20, 10);
	ft_printf("%10s h", "pepe");
	//printf("%-10c",'d');
	return (0);
}