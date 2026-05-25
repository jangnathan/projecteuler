// pandigital products
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
 * calculate factorial for total permutations so i can hardcode it
 *
int main() {
	unsigned int factorial = 1;
	for (int i = 9; i > 0; i--) {
		factorial *= i; }

	printf("%d", factorial);
}
*/

// 9! = 362880

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int numFromDigitsSegment(int start, int end, int input[9]) {
	int digits[end - start];
	int index = 0;
	for (int i = start; i < end; i++) {
		digits[index] = input[i];
		index++;
	}

	int num = 0;
	
	for (int i = 0; i < end - start; i++) {
		num += digits[i] * pow(10, (end - start) - i - 1);
	}

	return num;
}

int main() {
	int runningSum = 0;
	int products[30] = {0}; // guessing
	int productsIndex = 0;

	for (int p = 0; p < 362880; p++) {
		int numDigits = 9;
		int digitsLeft[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		int digits[9] = {0};
		int target = p;

		int digitIdx;

		// theres gonna be filler stuff, but just go until numDigits and there wont be issues
		while (numDigits > 0) {
			int fact = factorial(numDigits - 1);
			digitIdx = target / fact;

			digits[9-numDigits] = digitsLeft[digitIdx];

			for (int i = digitIdx; i < 9; i++) {
				digitsLeft[i] = digitsLeft[i + 1];
			}

			target = target % fact;
			numDigits--;
		}

		for (int multiplicandIndex = 1; multiplicandIndex < 9; multiplicandIndex++) {
			for (int multiplierIndex = 0; multiplierIndex < 9; multiplierIndex++) {
				if (multiplicandIndex + multiplierIndex >= 9) break;
				int multiplicand = numFromDigitsSegment(0, multiplicandIndex, digits);
				int multiplier = numFromDigitsSegment(multiplicandIndex, multiplicandIndex + multiplierIndex, digits);
				int product = numFromDigitsSegment(multiplicandIndex + multiplierIndex, 9, digits);

				if (multiplicand * multiplier == product) {
					printf("\n");
					printf("%d x %d = %d, ", multiplicand, multiplier, product);
					printf("%d %d %d, ", multiplicandIndex, multiplierIndex, 8);
					for (int i = 0; i < 9; i++) {
						printf("%d", digits[i]);
					}

					bool hasItem = false;
					for (int i = 0; i <= productsIndex; i++) {
						if (products[i] == product) {
							hasItem = true;
						}
					}

					if (!hasItem) {
						products[productsIndex] = product;
						productsIndex++;
					}
				}
			}
		}
	}

	printf("\n");
	for (int i = 0; i < 30; i++) {
		runningSum += products[i];
	}
	printf("%d ", runningSum);
}
