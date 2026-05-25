#include <stdio.h>

int isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int primeIndex = 0;
	int tryNum = 2;

	while (1) {
		if (isPrime(tryNum)) {
			primeIndex++;
			if (primeIndex == 10001) {
				break;
			}

		}

		tryNum++;
	}

	printf("%d", tryNum);
}
