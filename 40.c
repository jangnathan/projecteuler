// champernowne's constant
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int nthDigit(int nth) {
	int idx = 0;
	int num = 0;
	while (1) {
		num++;

		int nx = num;
		int numDigits = 0;
		while (nx != 0) {
			nx /= 10;
			numDigits++;
		}

		int stamp = idx;

		for (int i = 0; i < numDigits; i++) {
			idx++;

			if (idx == nth) {
				printf("%d", num);
				int digit = num / pow(10, numDigits - (idx - stamp));
				digit %= 10;
				printf(" %d \n", digit);
				return digit;
			}
		}
	}
}

int main() {
	printf("\n: %d", nthDigit(1000000) * nthDigit(100000) * nthDigit(10000) * nthDigit(1000) * nthDigit(100) * nthDigit(10) * nthDigit(1));
}
