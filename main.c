#include "ft_printf.h"
#include <stddef.h>
#include <stdio.h>
//869 69
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
	a = ft_printf("% d", 0);
	
	   printf("%i\n", a);

	   a = printf("% d", 0);
	
	   printf("%i", a);
	return (0);
}
/*
  TEST(10, print(" % d ", 0));
37:     TEST(12, print(" % d ", 1));
38:     TEST(13, print(" % d ", 9));
39:     TEST(14, print(" % d ", 10));
40:     TEST(15, print(" % d ", 11));
41:     TEST(16, print(" % d ", 15));
42:     TEST(17, print(" % d ", 16));
43:     TEST(18, print(" % d ", 17));
44:     TEST(19, print(" % d ", 99));
45:     TEST(20, print(" % d ", 100));
46:     TEST(21, print(" % d ", 101));
56:     TEST(31, print(" % d ", INT_MAX));
59:     TEST(34, print(" % d ", LONG_MIN));
63:     TEST(38, print(" % d % d % d % d % d % d % d", INT_MAX, INT_MIN, 
LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
65:     TEST(39, print(" % i ", 0));
67:     TEST(41, print(" % i ", 1));
68:     TEST(42, print(" % i ", 9));
69:     TEST(43, print(" % i ", 10));
70:     TEST(44, print(" % i ", 11));
*/