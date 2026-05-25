// triangular, pentagonal, hexagonal
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long unsigned int hexagonal(int n) {
	return n * (2 * n - 1);
}

bool isPentagonal(unsigned long x) {
    double n = (1.0 + sqrt(1 + 24 * x)) / 6.0;
    return n == (unsigned long)n;
}

int main() {
	int hn = 143;
	while (1) {
		hn++;
		if (isPentagonal(hexagonal(hn))) {
			printf("%lu", hexagonal(hn));
			break;
		};
	}
}
