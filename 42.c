// coded triangle numbers
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int indexOfAlphabet(char letter) {
	for (int i = 0; i < 26; i++) {
		if (letter == alphabet[i]) {
			return i; }
	}

	return 0;
}

int alphabeticValue(char word[], int len) {
	int value = 0;
	for (int i = 0; i < len; i++) {
		value += indexOfAlphabet(word[i]) + 1;
	}

	return value;
}

bool isTriangleNumber(int n) {
	int triangleNum = 0;
	for (int i = 1; triangleNum < n; i++) {
		triangleNum = (i * (i + 1)) / 2;
	}

	if (triangleNum == n) {
		return true;
	}
	return false;
}

int main() {
	FILE *file;

	file = fopen("files/42_words.txt", "r");

	char wordsUnparsed[16345];
	fgets(wordsUnparsed, 16345, file);

	int firstIndex = -1;

	char quotation = '\"';

	int count = 0;

	for (int i = 0; i < 16345 + 1; i++) {
		if (wordsUnparsed[i] == quotation) {
			if (firstIndex == -1) {
				firstIndex = i;
			} else {
				int len = i - firstIndex - 1;
				char word[len];

				for (int ch = 0; ch < len; ch++) {
					word[ch] = wordsUnparsed[firstIndex + ch + 1];
				}

				if (isTriangleNumber(alphabeticValue(word,len))) {
					count++;
				}

				firstIndex = -1;
			}
		}
	}

	printf("%d", count);
	printf("\n value: %d", alphabeticValue("SKY", 3));

	fclose(file);
}
