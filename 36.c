// double base palindromes
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPalindromeBase10(int num) {
	int reversedNumber = 0;
	int n = num;

	while (n > 0) {
		reversedNumber = reversedNumber * 10 + n % 10;
		n /= 10;
	}

	if (num == reversedNumber) {
		return true;
	}
	return false;
}

int minimumBit(int n) {
	int divisions = 0;

	while (n != 0) {
		n /= 2;
		divisions++;
	}

	int bits = 1;
	while (bits < divisions) {
		bits *= 2;
	}

	return bits;
}

bool isPalindromeBase2(int n) {
	int bits = minimumBit(n);
	bool binary[bits];

	for (int i = 0; i < bits; i++) {
		binary[i] = n % 2;
		n = floor(n / 2);
	}

	int leadingZeroIndex = bits;
	while (binary[leadingZeroIndex] == 0) {
		leadingZeroIndex--;
	}

	for (int i = 0; i < leadingZeroIndex + 1; i++) {
		if (binary[i] != binary[leadingZeroIndex - i]) {
			return 0;
		}
	}

	return 1;
}

bool isPalindrome(int n) {
	if (n == 0) {
		return true;
	}
	if (isPalindromeBase10(n) && isPalindromeBase2(n)) {
		return true;
	}
	return false;
}

int main() {
	long unsigned int total = 0;
	for (int n = 1; n < 1000000; n++) {
		if (isPalindrome(n)) {
			total += n;
		}
	}
	printf("%lu", total);
	return 0;
}
