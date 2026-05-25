// circular primes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n) {
	if (n == 1) {
		return false;
	}

	n = abs(n);
	int nsqrt = floor(sqrt(n));
	for (int i = 2; i <= nsqrt; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

bool isCircular(int n) {
	if (!isPrime(n)) {
		return false;
	} // immediately reject if
	
	if (n < 9) {
		return true;
	}

	int numDigits = 0;
	int nx = n; // to manipulate

	while (nx != 0) {
		numDigits += 1;
		nx /= 10;
	}

	int num = n;
	for (int i = 0; i < numDigits; i++) { // subtract one because we already verified at the start
		int firstDigitRemaining = (num % (int)pow(10, numDigits - 1)) * 10; // remaining with first digit taken off
		num = firstDigitRemaining + (num / pow(10, numDigits - 1));

		if (!isPrime(num)) {
			return false;
		}
	}

	return true;
}

int main() {
	int count = 0;

	for (int n = 2; n < 1000000; n++) {
		if (isCircular(n)) {
			count++;
		}
	}

	printf("count: %d", count);

	return 0;
}
