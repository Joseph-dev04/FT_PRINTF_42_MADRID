#include "ft_printf.h"
#include <stddef.h>
#include <stdio.h>
//937 1

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
	a = ft_printf(" %-2u ", -1);
	
	   printf("%i\n", a);

	   a = printf(" %-2u ", -1);
	
	   printf("%i", a);
	return (0);
}
/*
149:    TEST(118, print(" %-3x ", 1));
161:    TEST(130, print(" %-3x ", -11));
162:    TEST(131, print(" %-4x ", -14));
163:    TEST(132, print(" %-5x ", -15));
164:    TEST(133, print(" %-6x ", -16));
165:    TEST(134, print(" %-1x ", -99));
168:    TEST(137, print(" %-9x ", INT_MAX));
171:    TEST(140, print(" %-12x ", LONG_MIN));
173:    TEST(142, print(" %-14x ", ULONG_MAX));
174:    TEST(143, print(" %-15x ", 9223372036854775807LL));
175:    TEST(144, print(" %-9x %-10x %-11x %-12x %-13x %-14x %-15x", 
INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
177:    TEST(145, print(" %-1X ", 0));
179:    TEST(147, print(" %-3X ", 1));
191:    TEST(159, print(" %-3X ", -11));
192:    TEST(160, print(" %-4X ", -14));
193:    TEST(161, print(" %-5X ", -15));
194:    TEST(162, print(" %-6X ", -16));
195:    TEST(163, print(" %-1X ", -99));
198:    TEST(166, print(" %-9X ", INT_MAX));*/