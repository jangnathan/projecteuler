// smallest multiple
#include <stdio.h>
#include <math.h>

const int toNum = 20;

int isDivisibleTo(int num) {
	for (int i = 1; i < toNum; i++) {
		if (num % i != 0) {
			return 0;
		}
	}

	return 1;
}

int main() {
	int smallest = 1;

	while (1) {
		if (isDivisibleTo(smallest)) {
			break;
		}
		smallest++;
	}

	printf("%d", smallest);
}
