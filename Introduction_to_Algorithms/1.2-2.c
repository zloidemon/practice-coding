#include <stdio.h>
#include <math.h>

#define CONST1 8.0
#define CONST2 64.0

int main(void)
{
	double n = 0;
	double insert = 0.0, merge = 0.0;

	while (1) {
		if (insert > merge &&
			insert  != 0.0 &&
			merge != 0.0) break;

		insert = CONST1 * pow(n, 2.0);
		merge  = CONST2 * n * log2(n);
		++n;
	}

	printf("%.fn^2 = %f\n",     CONST1, insert);
	printf("%.fnlog(n) = %f\n", CONST2, merge);

	printf("result: %f\n", n);

	return 0;
}
