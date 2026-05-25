// truncable primes
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
	if (n == 1) return false;

	int nsqrt = floor(sqrt(n));
	for (int i = 2; i <= nsqrt; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

bool isTruncablePrime(int n) {
	if (!isPrime(n)) return false;

	int nx = n;
	int numDigits = 1;

	while (nx > 9) {
		if (!isPrime(nx / 10)) return false;
		if (!isPrime(n % (int)pow(10, numDigits))) return false;

		nx /= 10;
		numDigits++;
	}
	return true;
}

int main() {
	int total = 0;
	int numTruncablePrimes = 0;
	for (int n = 11; n < 1000000; n++) {
		if (isTruncablePrime(n)) {
			printf("%d ", n);
			total += n;
			numTruncablePrimes++;
		}
	}

	printf("\n%d %d", total, numTruncablePrimes);
}
