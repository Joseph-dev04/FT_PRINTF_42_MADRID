#include "ft_printf.h"
#include <stddef.h>
#include <stdio.h>
//869 69
int main()
{
	int a = 10;
	void *p;
	p = &a;
	char *s = "hola";
	
	/*if ((long)p > 10)
	{
		printf("%p hola \"original\"\n", p);
	}*/
	//ft_printf("%s %c %i %x %X ", "hola", 'd', 10, 20, 10);
	a = ft_printf("%70p",p);
	
	   printf("%i\n", a);

	   a = printf("%70p",p);
	
	   printf("%i", a);
	return (0);
}
/*
- [OUTPUT] ft_printf("%8.5i", 34)
- [OUTPUT] ft_printf("%10.5i", -216)
- [OUTPUT] ft_printf("%8.5i", 0)
- [OUTPUT] ft_printf("%-8.5i", 34)
- [OUTPUT] ft_printf("%-10.5i", -216)
- [OUTPUT] ft_printf("%-8.5i", 0)
- [OUTPUT] ft_printf("%-3.7i", 3267)
- [OUTPUT] ft_printf("%-3.7i", -2375)
- [OUTPUT] ft_printf("%08.5i", 34)
- [OUTPUT] ft_printf("%010.5i", -216)
- [OUTPUT] ft_printf("%08.5i", 0)
- [OUTPUT] ft_printf("%08.3i", 8375)
- [OUTPUT] ft_printf("%.0i", 0)
- [OUTPUT] ft_printf("%.i", 0)
- [OUTPUT] ft_printf("%5.0i", 0)
- [OUTPUT] ft_printf("%5.i", 0)
- [OUTPUT] ft_printf("%-5.0i", 0)
- [OUTPUT] ft_printf("%-5.i", 0)
- [OUTPUT] ft_printf("%8.5d", 34)
- [OUTPUT] ft_printf("%10.5d", -216)*/