/*

gcc -march=haswell -o 0001_snoob{,.c}

*/

#include <stdio.h>
#include "utils.h"

unsigned snoob(unsigned);
unsigned snoob_ntz(unsigned);
unsigned snoob_nlz(unsigned);
unsigned snoob_pop(unsigned);

unsigned snoob(unsigned x) {
	unsigned smallest, ripple, ones;

	smallest	= x & -x;
	ripple		= x + smallest;
	ones		= x ^ ripple;
	ones		= (ones >> 2) / smallest;
	return ripple | ones;
}

/*
 GCC __builtin_ctz Returns the number of trailing 0-bits in x
*/

unsigned snoob_ntz(unsigned x) {
	unsigned smallest, ripple, ones;

	smallest	= x & -x;
	ripple		= x + smallest;
	ones		= x ^ ripple;
	ones		= ones >> (2 + __builtin_ctz(smallest));
	return ripple | ones;
};

/*
 GCC __builtin_clz Returns the number of leading 0-bits in x
*/

unsigned snoob_nlz(unsigned x) {
	unsigned smallest, ripple, ones;

	smallest	= x & -x;
	ripple		= x + smallest;
	ones		= x ^ ripple;
	ones		= ones >> (33 - __builtin_clz(smallest));
	return ripple | ones;
};

/*
 GCC __builtin_popcount Returns the number of 1-bits in x
*/

unsigned snoob_pop(unsigned x) {
	unsigned smallest, ripple, ones;

	smallest	= x & -x;
	ripple		= x + smallest;
	ones		= x ^ ripple;
	ones		= (1 << (__builtin_popcount(ones) - 2)) -1;
	return ripple | ones;
};

int main() {
	unsigned x;
	unsigned print_bits = 7;

	for (x = 1; x <= 127; ++x) {
		printf("%03d\t", x);
		bin(x, print_bits);
		printf("%03d\t", snoob(x), print_bits);
		bin(snoob(x), print_bits);
		bin(snoob_ntz(x), print_bits);
		bin(snoob_nlz(x), print_bits);
		bin(snoob_pop(x), print_bits);
		printf("\n");
	};

	return 0;
}
