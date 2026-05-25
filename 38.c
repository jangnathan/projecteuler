// pandigital multiples
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int numFromDigits(int digits[], int len) {
	int num = 0;
	
	for (int i = 0; i < len; i++) {
		num += digits[i] * pow(10, len - i - 1);
	}

	return num;
}

int concatenatedPandigital(int num) {
	int digits[9] = {0};
	int index = 0;
	int multiplier = 1;
	int stamp = 0;

	while (1) {
		int product = num * multiplier;
		int numDigits = 0;

		int nx = product;
		while (nx != 0) {
			if (nx % 10 == 0) return 0; // break if it has a 0
			nx /= 10;
			numDigits++;
		}

		for (int digitIdx = 0; digitIdx < numDigits; digitIdx++) {
			int digit = product % 10;

			//printf("\n index (real): %d value: %d index: %d \n", stamp + numDigits - digitIdx - 1, digit, index);
			if (stamp + numDigits - 1 > 8) return 0;
			digits[stamp + numDigits - digitIdx - 1] = digit;
			product /= 10;

			if (index > 8) return 0;
			index++;
		}
		stamp = index;

		if (index == 9) {
			// its perfect
			for (int i = 0; i < stamp; i++) {
				for (int x = 0; x < stamp; x++) {
					if (digits[i] == digits[x] && x != i) {
						return 0;
					}
				}
			}
			return numFromDigits(digits, 9);
		}

		multiplier++;
	}
}

int main() {
	int largest = 0;
	for (int n = 2; n < 10000; n++) {
		int pandigital = concatenatedPandigital(n);
		if (pandigital > largest) {
			largest = pandigital;
		}
	}

	printf("%d", largest);
}
