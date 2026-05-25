// quadratic primes
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool isPrime(int n) {
	n = abs(n);
	int nsqrt = ceil(sqrt(n));
	for (int i = 2; i < nsqrt; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int maxNumOfPrimes = 0;
	int maxNumOfPrimesA = 0;
	int maxNumOfPrimesB = 0;

	for (int a = -999; a < 1000; a++) {
		for (int b = -1000; b <= 1000; b++) {
			int n = 0;

			int value = pow(n, 2) + (n * a) + b;
			while (isPrime(value)) {
				n++;
				value = pow(n, 2) + (n * a) + b;
			}

			if (n > maxNumOfPrimes) {
				maxNumOfPrimes = n;
				maxNumOfPrimesA = a;
				maxNumOfPrimesB = b; 
			}
		}
	}

	printf("a: %d \n b: %d \n product: %d \n max n: %d", maxNumOfPrimesA,maxNumOfPrimesB,maxNumOfPrimesA*maxNumOfPrimesB,maxNumOfPrimes);
}
