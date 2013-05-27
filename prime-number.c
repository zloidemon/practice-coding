#include <stdio.h>
#include <math.h>

unsigned int check_prime(const unsigned int);
unsigned int ferma_prime(const unsigned int, const unsigned int);


int main(void)
{
	unsigned int val, iter, limit = 200;

	for (iter = 1; iter <= limit; ++iter) {
		val = ferma_prime(2, iter);

		if (val != 0) {
			printf("Prime %d\n", val);
			val = 0;
		}
	}

	return 0;
}

unsigned int
ferma_prime(const unsigned int a, const unsigned int prime)
{
	if (1 == ((long)pow((double)a, (double)prime - 1)%(long)prime)) {
		return prime;
	} else {
		return 0;
	}
}

unsigned int
check_prime(const unsigned int prime)
{
	unsigned int iter, rem;
	unsigned short self = 1;

	for (iter = 1; iter <= prime; ++iter) {
		rem = prime%iter;
		if (0 == rem && iter < prime && iter != 1) {
			self = 0; 
			break;
		}
	}

	if (1 == self) {
		return prime;
	} else {
		return 0;
	}
}
