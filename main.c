#include "ft_printf.h"
#include <stddef.h>
#include <stdio.h>

int main()
{
	int a = 10;
	void *p;
	p = &a;
	char *s = NULL;
	
	/*if ((long)p > 10)
	{
		printf("%p hola \"original\"\n", p);
	}*/
	//ft_printf("%s %c %i %x %X ", "hola", 'd', 10, 20, 10);
	a = ft_printf(" %-10i ", 10);
	
	   printf("%i\n", a);

	   a = printf(" %-10i ", 10);
	
	   printf("%i", a);
	return (0);
}