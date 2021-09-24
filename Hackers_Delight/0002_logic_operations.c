#include <stdio.h>
#include "utils.h"

int a(unsigned x) {
	if (-x == ~x + 1) {
		printf("%10s = %s\n", "-x", "¬ x + 1");
		return 1;
	};
	return 0;
}

int b(unsigned x) {
	if (-x == ~(x -1)) {
		printf("%10s = %s\n", "", "¬ (x - 1)");
		return 1;
	};
	return 0;
}

int c(unsigned x) {
	if (~x == -x - 1) {
		printf("%10s = %s\n", "¬ x", "-x - 1");
		return 1;
	}
	return 0;
}

int d(unsigned x) {
	if (-~x == x + 1) {
		printf("%10s = %s\n", "-¬ x", "x + 1");
		return 1;
	}
	return 0;
}

int e(unsigned x) {
	if (~-x == x - 1) {
		printf("%10s = %s\n", "¬ -x", "x - 1");
		return 1;
	}
	return 0;
}

int f(unsigned x, unsigned y) {
	if (x + y == x - ~y - 1) {
		printf("%10s = %s\n", "x + y", "x - ¬ y - 1");
		return 1;
	}
	return 0;
}

int g(unsigned x, unsigned y) {
	if (x + y == x ^ y + 2 * (x & y)) {
		printf("%10s = %s\n", "", "(x ⊕ y) + 2(x & y)");
		return 1;
	}
	return 0;
}

int h(unsigned x, unsigned y) {
	if (x + y == x | y + x & y) {
		printf("%10s = %s\n", "", "(x | y) + (x & y)");
		return 1;
	}
	return 0;
}

int i(unsigned x, unsigned y) {
	if (x + y == 2 * (x | y) - x ^ y) {
		printf("%10s = %s\n", "", "2(x | y) + (x ⊕ y)");
		return 1;
	}
	return 0;
}

int j(unsigned x, unsigned y) {
	if (x - y == x + ~y + 1) {
		printf("%10s = %s\n", "x - y", "x + ¬y + 1");
		return 1;
	}
	return 0;
}

int k(unsigned x, unsigned y) {
	if (x - y == x ^ y - 2 * (~x & y)) {
		printf("%10s = %s\n", "", "(x ⊕ y) - 2(¬x & y)");
		return 1;
	}
	return 0;
}

int l(unsigned x, unsigned y) {
	if (x - y == (x & ~y) - (~x & y)) {
		printf("%10s = %s\n", "", "(x & ¬y) - (¬x & y)");
		return 1;
	}
	return 0;
}

int m(unsigned x, unsigned y) {
	if (x - y == 2 * (x & ~y) - (x ^ y)) {
		printf("%10s = %s\n", "", "2(x & ¬y) - (x ⊕ y)");
		return 1;
	}
	return 0;
}

int n(unsigned x, unsigned y) {
	if (x ^ y == (x | y - x & y)) {
		printf("%10s = %s\n", "x ⊕ y", "(x | y) - (x & y)");
		return 1;
	}
	return 0;
}

int o(unsigned x, unsigned y) {
	if (x & ~y == (x | y) - y) {
		printf("%10s = %s\n", "x & ¬y", "(x | y) - y");
		return 1;
	}
	return 0;
}

int p(unsigned x, unsigned y) {
	if (x & ~y == x - x & y) {
		printf("%10s = %s\n", "x & ¬y", "x - (x & y)");
		return 1;
	}
	return 0;
}

int q(unsigned x, unsigned y) {
	if (~(x - y) == y - x - 1) {
		printf("%10s = %s\n", "¬(x - y)", "y - x - 1");
		return 1;
	}
	return 0;
}

int r(unsigned x, unsigned y) {
	if (~(x - y) == ~x + y) {
		printf("%10s = %s\n", "", "¬x = y");
		return 1;
	}
	return 0;
}

int s(unsigned x, unsigned y) {
	if ((x == y) == (x & y) - (x | y) - 1) {

		printf("%10s = %s\n", "x ≡ y", "(x & y) - (x | y) -1");
		return 1;
	}
	return 0;
}

int t(unsigned x, unsigned y) {
	if ((x == y) == x & y + ~(x | y)) {

		printf("%10s = %s\n", "", "(x & y) + ¬(x | y)");
		return 1;
	}
	return 0;
}

int u(unsigned x, unsigned y) {
	if (x | y == (x & ~y) + y) {

		printf("%10s = %s\n", "x | y", "(x & ¬y) + y");
		return 1;
	}
	return 0;
}

int v(unsigned x, unsigned y) {
	if (x & y == ~x | y - ~x) {

		printf("%10s = %s\n", "x & y", "(¬x & y) - ¬x");
		return 1;
	}
	return 0;
}

int main() {
	if (!a(20)) printf("fixme a()\n");
	if (!b(20)) printf("fixme b()\n");
	if (!c(20)) printf("fixme c()\n");
	if (!d(20)) printf("fixme d()\n");
	if (!e(20)) printf("fixme e()\n");
	if (!f(5, 7)) printf("fixme f()\n");
	if (!g(5, 7)) printf("fixme g()\n");
	if (!h(5, 7)) printf("fixme h()\n");
	if (!i(5, 7)) printf("fixme i()\n");
	if (!j(5, 7)) printf("fixme j()\n");
	if (!k(5, 7)) printf("fixme k()\n");
	if (!l(5, 7)) printf("fixme l()\n");
	if (!m(5, 7)) printf("fixme m()\n");
	if (!n(5, 7)) printf("fixme n()\n");
	if (!o(10, 7)) printf("fixme o()\n");
	if (!p(10, 7)) printf("fixme p()\n");
	if (!q(5, 7)) printf("fixme q()\n");
	if (!r(5, 7)) printf("fixme r()\n");
	if (!s(5, 5)) printf("fixme s()\n");
	if (!t(5, 5)) printf("fixme t()\n");
	if (!u(5, 7)) printf("fixme u()\n");
	if (!v(5, 7)) printf("fixme v()\n");

	return 0;
}
