// digit fifth power
#include <stdio.h>
#include <math.h>

int main() {
	int runningSum = 0;

	for (int i = 2; i <= 999999; i++) {
		int digits = i;
		int check = 0;

		for (int d = 0; d < 6; d++) {
			int digit = digits % 10;
			check += pow(digit , 5);

			digits /= 10;
		}

		if (check == i) {
			runningSum += i;
		}
	}

	printf("%d", runningSum);
}
