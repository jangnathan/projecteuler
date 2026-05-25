// number letter counts
#include <stdio.h>

// one, two, three, four, five, six, seven, eight, nine
const int ones[10] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};

// eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
const int teens[10] = {0, 6, 6, 8, 8, 7, 7, 9, 8, 8};

// ten, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
const int tens[10] = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};

// one hundred, two hundred, three hundred, four hundred, five hundred, six hundred, seven hundred, eight hundred, nine hundred
const int hundreds[10] = {0,
	3 + 7,
	3 + 7,
	5 + 7,
	4 + 7,
	4 + 7,
	3 + 7,
	5 + 7,
	5 + 7,
	4 + 7};

int main() {
	int runningSum = 0;
	for (int n = 1; n < 1000; n++) {
		int numCharLen = 0;

		if (n >= 100 && n < 1000) {
			numCharLen += hundreds[n / 100];
			if (n % 100 != 0) {
				// and is 3 letters
				numCharLen += 3;
			}
		}

		if (n % 100 > 10 && n % 100 < 20) {
			numCharLen += teens[n % 10];
		} else {
			numCharLen += tens[(n % 100) / 10];
			numCharLen += ones[n % 10];
		}

		runningSum += numCharLen;
	}
	// one thousand
	runningSum += 3 + 8;

	printf("%d", runningSum);
}
