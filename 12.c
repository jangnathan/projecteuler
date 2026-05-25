#include <stdio.h>
#include <math.h>

int main() {
	int i = 1;
	long int n = 0;
	while (1) {
		n += i;
		i++;

		int divisors = 2;
		int root = sqrt(n);
		for (int x = 2; x < root; x++) {
			if (n % x == 0) {
				divisors++;
			}
		}
		divisors *= 2;

		if (divisors > 500) {
			printf("%d \n", divisors);
			printf("%ld", n);
			break;
		}
	}
}
