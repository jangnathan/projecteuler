#include <stdio.h>

int collatzLen(int num) {
	int len = 1;
	unsigned int n = num;

	while (n != 1) {
		len++;
		if (n % 2 == 0) {
			n = n / 2;
		} else {
			n = (3 * n) + 1;
		}
	}

	return len;
}

int main() {
	int largest = 0;
	int largestSequenceNum = 0;
	int collatzLength = 0;

	for (int i = 1; i < 1000000; i++) {
		collatzLength = collatzLen(i);

		if (collatzLength > largest) {
			largestSequenceNum = i;
			largest = collatzLength;
		}
	}

	printf("%d", largestSequenceNum);
}
