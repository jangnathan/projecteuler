// multiples of 3 or 5
#include <stdio.h>

int main() {
	int runningSum = 0;

	for (int i = 1; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			runningSum += i;
		}
	}

	printf("%d", runningSum);
}
