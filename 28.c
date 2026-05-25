// number spiral diagonals

#include <stdio.h>
#include <math.h>

int main() {
	int runningSum = 1;
	int n = 1;
	int biggestOfCorner = 1;
	int biggestOfCornerRoot = 1; 
	int addN = 0;

	while (n != 1001 * 1001) {
		if (n >= biggestOfCorner) {
			biggestOfCornerRoot+=2;
			biggestOfCorner = pow(biggestOfCornerRoot, 2);
			addN += 2;
		}
		n += addN;

		runningSum += n;
	}

	printf("%d", runningSum);
}
