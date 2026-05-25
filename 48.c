// self powers
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

const uint64_t tenDigits = 10000000000;

int main() {
	uint64_t lastTenDigits = 0;
	for (int i = 1; i <= 1000; i++) {
		uint64_t num = i;

		for (int x = 0; x < i - 1; x++) {
			num *= i;
			num %= tenDigits;
		}

		lastTenDigits += num;
		lastTenDigits %= tenDigits;
	}

	printf("%llu", lastTenDigits);
}
