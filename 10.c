// summation of primes
#include <stdio.h>
#include <math.h>

int isPrime(int n) {
	for (int x = 2; x <= ceil(sqrt(n)); x++) {
		if (n % x == 0) {
			return 0;
		}
	}

	return 1;
}

int main() {
	long int runningSum = 2;
	for (int i = 2; i < 2000000; i++) {
		if (isPrime(i)) {
			if (i < 50) {
				printf("%d \n", i);
			}
			runningSum += i;
		}
	}

	printf("%ld", runningSum);
}
