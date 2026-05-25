// amicable numbers
#include <stdio.h>
#include <math.h>

int isAmicablePair(int x, int y) {
	if (x == y) {
		return 0;
	}

	int x_sum = 1; // 1 because all have divisor 1
	float x_sqrt = sqrt(x);
	if (x_sqrt == floor(x_sqrt)) { // whole number
		x_sum += x_sqrt;
	}
	for (int n = 2; n < floor(x_sqrt); n++) {
		if (x % n == 0) {
			x_sum += n;
			x_sum += x / n;
		}
	}

	int y_sum = 1; // 1 because all have divisor 1
	float y_sqrt = sqrt(y);
	if (y_sqrt == floor(y_sqrt)) {
		y_sum += y_sqrt;
	}
	for (int n = 2; n < floor(y_sqrt); n++) {
		if (y % n == 0) {
			y_sum += n;
			y_sum += y / n;
		}
	}

	if (x_sum == y && y_sum == x) {
		return 1;
	}

	return 0;
}

int main() {
	int runningSum = 0;
	int lastAmicableY = 284;
	for (int x = 220; x <= 10000; x++) {
		for (int y = lastAmicableY; y <= 10000; y++) {
			if (isAmicablePair(x, y)) {
				runningSum += x + y;

				printf("%d %d ,", x, y);

				lastAmicableY = y;
			}
		}
	}
	printf("\n %d", runningSum);
}
