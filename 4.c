// largest palindrome number
#include <stdio.h>

int isPalindrome(int num) {
	int reversedNumber = 0;
	int n = num;

	while (n > 0) {
		reversedNumber = reversedNumber * 10 + n % 10;
		n /= 10;
	}

	if (num == reversedNumber) {
		return 1;
	}
	return 0;
}

int main() {
	int largest = 0;

	for (int x = 0; x <= 999; x++) {
		for (int y = 0; y <= 999; y++) {
			if (isPalindrome(x * y)) {
				if (x * y > largest) {
					largest = x * y;
				}
			}
		}
	}

	printf("%d", largest);
}
