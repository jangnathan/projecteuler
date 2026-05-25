// even fibbonacci numbers
#include <stdio.h>

int main() {
	int prevNumber = 1;
	int secondPrevNumber = 0;
	int runningSum = 0;
	int i;

	while (i < 4000000) {
		i = prevNumber + secondPrevNumber;
		secondPrevNumber = prevNumber;
		prevNumber = i;

		if (i % 2 == 0) {
			runningSum += i;
		}
	}

	printf("%d", runningSum);
}
