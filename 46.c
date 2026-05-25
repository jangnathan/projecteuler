// goldbach's other conjecture
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;

	int nsqrt = ceil(sqrt(n));
	for (int i = 2; i <= nsqrt; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int i = 9;

	while (1) {
		i++;

		if (i % 2 == 0) {
			continue;
		}

		if (isPrime(i)) {
			continue;
		}

		bool isResult = true;
		for (int x = 2; x < i; x++) {
			if ((i - x) % 2 != 0) continue;
			if (isPrime(x)) {
				int latter = i - x;

				float latterCheck = sqrt(latter/2);
				if (latterCheck == (int)latterCheck) {
					isResult = false;
					break;
				}
			}
			
		}
		if (isResult) {
			printf("\n %d", i);
			return 0;
		}
	}
}
