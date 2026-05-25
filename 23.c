// non-abundant sums
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isAbundant(int n) {
	float rootn = sqrt(n);

	int sum = 1; // because 1 counts already
	
	if (floor(rootn) == rootn) {
		sum += rootn; // add it once because no duplicates
	}

	for (int i = 2; i < rootn; i++) {
		if (n % i == 0) {
			sum += i;
			sum += n / i;
		}
	}

	if (sum > n) {
		return true;
	}
	return false;
}

const int abundantNumLen = 7456; // any number, theres a specific amount just get over it
static int abundantNums[abundantNumLen] = {0};

bool isSumOfTwoAbundantNums(int n) {
	for (int x = 0; x <= abundantNumLen; x++) {
		int target = n - abundantNums[x];
		if (target == 0) return false;

		int low = 0, high = abundantNumLen;
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (abundantNums[mid] == target) {
				return true;
			}
			else if (abundantNums[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return false;
}

int main() {
	unsigned long long int runningSum = 0;

	// find out how much space we need & for the index 
	int abundantNumCount = 0;

	// get all abundantNumbers under 28123
	for (int i = 2; i <= 28123; i++) {
		if (isAbundant(i)) {
			abundantNums[abundantNumCount] = i;
			abundantNumCount++;
		}
	}

	// find sum of positive integers that cannot be made of sums of two abundant numbers
	for (int i = 1; i <= 28123; i++) {
		if (!isSumOfTwoAbundantNums(i)) {
			runningSum += i;
			//printf("%d ", i);
		}
	}

	printf("result %llu", runningSum);
	printf("\n analysis %d", abundantNumCount);
}
