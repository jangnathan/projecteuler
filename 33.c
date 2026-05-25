// digit cancelling fractions
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// just guessing triviality

int main() {
	int totalNumerator = 1;
	int totalDenominator = 1;
	for (int d = 99; d > 10; d--) {
		if (d % 10 == 0 || d % 11 == 0) continue;

		for (int n = d; n > 10; n--) {
			if (n % 10 == 0 || n % 11 == 0) continue;

			float value = (float)n / (float)d;

			if (value >= 1.0) continue;

			if (n % 10 != d / 10) continue;
			float tensxones = (n / 10) / (float)(d % 10);

			if (value == tensxones) {
				totalNumerator *= n;
				totalDenominator *= d;
				printf("\n %f ", value);
				printf("%d / %d", n, d);
			}
		}
	}

	printf("\n%d / %d = %f", totalNumerator, totalDenominator, (float)totalNumerator / (float)totalDenominator);
	// its 0.01 which is 1 / 100 
}
