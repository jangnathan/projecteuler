// digit factorials
// find the cap (test around)
#include <stdio.h>

int factorial(int n) {
	if (n <= 1) {
		return 1;
	}

	return n * factorial(n - 1);
}

int main() {
	int totalSum = 0;
	for (int i = 3; i < 100000; i++) {
		int tempSum = 0;
		int n = i;
		while (n != 0) {
			tempSum += factorial(n % 10);
			n /= 10;
		}

		if (tempSum == i) {
			totalSum += i;
		}
	}

	printf("\n%d", totalSum);
}
