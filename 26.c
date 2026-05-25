// reciprocal cycles
#include <stdio.h>
#include <math.h>

int recurringCycleOf1(int n) {
	int recurringLen = 0;

	int numDigits = 1;
	if (n > 100) {
		numDigits = 3;
	} else if (n > 10) {
		numDigits = 2;
	}

	int numerator = pow(10, numDigits);
	int digits[numerator + numDigits];

	// clear
	for (int i = 0; i < numerator + numDigits; i++) {
		digits[i] = 0;
	}

	int divide = 1;
	for (int i = 0; i < numerator + numDigits; i++) {
		digits[i] = (divide * numerator) / n;
		divide = (divide * numerator) % n;

		if (i > numDigits - 1) {
			for (int x = i - 1; x >= numDigits - 1; x--) {
				for (int y = 0; y < numDigits; y++) {
					if (digits[i - y] == digits[x - y]) {
						return i;
						// theres been duplicate
					}
				}
			}
		}

		//printf("%d", digits[i]);
	}

	return recurringLen;
}

int main() {
	int d;
	int d_longest = 0;
	int d_longest_index = 0;

	for (int d = 2; d < 1000; d++) {
		int recurring = recurringCycleOf1(d);

		if (recurring > d_longest) {
			d_longest = recurring;
			d_longest_index = d;
		}
	}

	printf("\n %d", d_longest_index);
}
