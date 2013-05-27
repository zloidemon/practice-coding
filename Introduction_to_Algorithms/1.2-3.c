#include <stdio.h>
#include <math.h>

int main(void)
{
	double n = 1;
	double first = 0.0, second = 0.0;

	while (1) {
		if (first < second) break;
		first  = 100 * pow(n, 2);
		second = pow(2, n);
		++n;
	}

	printf("100n^2 = %f\n", first);
	printf("2^n = %f\n",    second);

	printf("result: %f\n", n);
	return 0;
}
