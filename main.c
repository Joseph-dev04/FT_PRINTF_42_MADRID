#include "ft_printf.h"
#include <stddef.h>
#include <stdio.h>
//572 366
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
	a = ft_printf("%3.s", s);
	
	   printf("%i\n", a);

	   a = printf("%3.s", s);
	
	   printf("%i", a);
	return (0);
}