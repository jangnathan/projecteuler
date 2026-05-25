// pentagon numbers
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long unsigned int pentagon(int n) {
	return n * (3 * n - 1) / 2;
}

bool isPentagonal(unsigned long x) {
    double n = (1.0 + sqrt(1 + 24 * x)) / 6.0;
    return n == (unsigned long)n;
}

bool result(long unsigned int D) {
	float sqrtD = sqrt(D * 2);

	if (sqrtD == (int)sqrtD) {
		int A, B = (int)sqrtD;

		if (D * 2 >= 3 * pow(A, 2) &&
			B + 1 % 3 == 0 &&
			(B + 1) / 3 - A % 2 == 0) {
			return true;
		}
	}
	for (int A = 1; A < sqrtD; A++) {
		if ((2 * D) % A == 0) {
			long unsigned int B = (2 * D) / A;

			if (2 * D >= 3 * pow(A, 2)) {
				if ((B + 1) % 3 == 0) {
					if (((B + 1) / 3 - A) % 2 == 0) {
						int j = ((B + 1) / 3 - A) / 2;
						int k = A + j;
						if (isPentagonal(pentagon(k) + pentagon(j))) {
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}

int main() {
	int D = 0;
	int i = 1;
	while (1) {
		unsigned long int D = pentagon(i);
		i++;
		if (result(D)) {
			printf("\n%lu", D);
			break;
		}
	}
}
