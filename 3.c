// largest prime factor
#include <stdio.h>

int findPrime(long int n) {
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			return i;
		}
	}
	return 1;
}

int main() {
	long int n = 600851475143;
	int largestPrimeFactor = 2;

	int i;

	while (n != i) {
		i = findPrime(n);
		n /= i;

		if (i > largestPrimeFactor) {
			largestPrimeFactor = i;
			printf("%d \n", largestPrimeFactor);
		}
	}

}
