// pandigital prime
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int n) {
	n = abs(n);
	int nsqrt = ceil(sqrt(n));
	for (int i = 2; i < nsqrt; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int numFromDigits(int digits[], int len) {
	int num = 0;
	
	for (int i = 0; i < len; i++) {
		num += digits[i] * pow(10, len - i - 1);
	}

	return num;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
	int largest = 0;

	for (int n = 2; n <= 9; n++) { // 9 is max digits
		for (int permutation = 0; permutation < factorial(n); permutation++) {
			int numDigits = n;
			int digitsLeft[n];
			int digits[n]; 
			for (int i = 0; i < n; i++) {
				digits[i] = 0;
				digitsLeft[i] = i + 1;
			}
			int target = permutation;

			int digitIdx;

			// theres gonna be filler stuff, but just go until numDigits and there wont be issues
			while (numDigits > 0) {
				int fact = factorial(numDigits - 1);
				digitIdx = target / fact;

				digits[n-numDigits] = digitsLeft[digitIdx];

				for (int i = digitIdx; i < n; i++) {
					digitsLeft[i] = digitsLeft[i + 1];
				}

				target = target % fact;
				numDigits--;
			}

			int num = numFromDigits(digits, n);

			if (isPrime(num)) {
				if (num > largest) {
					largest = num;
				}
			}
		}
	}

	printf("%d", largest);
}
