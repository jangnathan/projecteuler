#include <stdio.h>

int main() {
	int sumOfSquares = 0;
	int squareOfSum = 0;

	for (int i = 1; i <= 100; i++) {
		sumOfSquares += i*i;
		squareOfSum += i;
	}

	squareOfSum *= squareOfSum;

	int difference = squareOfSum - sumOfSquares;
	printf("%d", difference);
}
