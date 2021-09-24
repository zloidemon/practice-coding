#include <stdio.h>

void bin(unsigned, unsigned);

void bin(unsigned n, unsigned bits)
{
	unsigned i;
	printf("0x");
	for (i = 1 << bits; i > 0; i = i / 2)
		(n & i) ? printf("1") : printf("0");
	printf("\t");
}
 
