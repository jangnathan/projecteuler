// distinct prime factors
#include <stdio.h>
#include <stdbool.h>

bool fourDistinctPrimes(int n) {
	// initializer
	// 1, 2, 3
	static int primeFactors[4][4] = {{0}};

	int nx, prime, count;
	nx = n;
	prime = 2;
	count = 0;

	for (int i = 4; i >= 0; i--) {
		for (int x = 0; x < 4; x++) {
			//printf("\nhelp:%d %d %d", i, x, primeFactors[i][x]);
			primeFactors[i][x] = primeFactors[i - 1][x];
		}
	}

	while (nx != 1) {
		if (nx % prime == 0) {
			count++;

			if (count > 4) {
				for (int x = 0; x < 4; x++) {
					for (int y = 0; y < 4; y++) {
						primeFactors[x][y] = 0;
					}
				}
				return false;
			}

			bool isDuplicate = false;
			for (int i = 0; i < 4; i++) {
				if (primeFactors[0][i] == prime && i != count - 1) {
					primeFactors[0][i] = prime * prime; // 2^2 type scenarios
					count--;
					isDuplicate = true;
					break;
				}
			}

			if (!isDuplicate) {
				primeFactors[0][count - 1] = prime;
			}

			nx /= prime;
			prime = 1;
		}
		prime++;
	}

	if (count < 4) {
		for (int i = count; i < 4; i++) {
			primeFactors[0][i] = 0;
		}
		return false;
	}

	for (int i = 0; i < 16; i++) { // 4 * 4
		for (int x = 0; x < 16; x++) { // 4 * 4
			if (primeFactors[i / 4][i % 4] == primeFactors[x / 4][x % 4] && i != x) {
				return false; // theres a duplicate
			}
			if (primeFactors[i / 4][i % 4] == 0) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	int n = 100;

	while (1) {
		n++;
		if (fourDistinctPrimes(n)) {
			printf("\n distinct: %d \n", n); // minus 3 to get first number
			break;
		}
	}
}
