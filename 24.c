// lexographic permutations
#include <stdio.h>
#include <math.h>

/*
 * calculate factorial for total permutations so i can hardcode it
 *
int main() {
	unsigned int factorial = 1;
	for (int i = 10; i > 0; i--) {
		factorial *= i;
	}

	printf("%d", factorial);
}
*/

// 10! = 3628800

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
	int numDigits = 10;
	int digitsLeft[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int digits[10] = {0};
	int target = 999999;

	int digitIdx;

	// theres gonna be filler stuff, but just go until numDigits and there wont be issues
	while (numDigits > 0) {
		int fact = factorial(numDigits - 1);
		digitIdx = target / fact;

		digits[10-numDigits] = digitsLeft[digitIdx];

		for (int i = digitIdx; i < 10; i++) {
			digitsLeft[i] = digitsLeft[i + 1];
		}

		target = target % fact;
		numDigits--;
	}

	printf("result:");
	for (int i = 0; i < 10; i++) {
		printf("%d", digits[i]);
	}
}
