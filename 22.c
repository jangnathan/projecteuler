// name scores
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

bool isAlphabeticallyGreater(char a[], char b[]) {
	if (b[0] == 0) {
		return true;
	} else if (a[0] == 0) {
		return false;
	}

	if (strlen(a) < strlen(b)) {
		for (int i = 0; i < strlen(a); i++) {
			int alphabetIndexA = indexOfAlphabet(a[i]);
			int alphabetIndexB = indexOfAlphabet(b[i]);

			if (alphabetIndexA > alphabetIndexB) {
				return false;
			} else if (alphabetIndexA < alphabetIndexB) {
				return true;
			}
		}

		return true;
	} else {
		for (int i = 0; i < strlen(b); i++) {
			int alphabetIndexA = indexOfAlphabet(a[i]);
			int alphabetIndexB = indexOfAlphabet(b[i]);

			if (alphabetIndexA > alphabetIndexB) {
				return false;
			} else if (alphabetIndexA < alphabetIndexB) {
				return true;
			}
		}

		return false;
	}
}

int main() {
	FILE *file;

	file = fopen("files/22-names.txt", "r");

	char namesUnparsed[46448];
	fgets(namesUnparsed, 46448, file);

	int firstIndex = -1;

	char quotation = '\"';

	// we found how much there is from previous running analysis
	char names[5162][12] = {{0}};

	int namesCount = 0;
	int largestNameChar = 0;

	for (int i = 0; i < 46447 + 1; i++) {
		if (namesUnparsed[i] == quotation) {
			if (firstIndex == -1) {
				firstIndex = i;
			} else {
				// this is when done

				int nameLen = i - firstIndex - 1;
				char name[12] = {0};

				for (int ch = 0; ch < nameLen; ch++) {
					name[ch] = namesUnparsed[firstIndex + ch + 1];
				}

				int x;
				for (x = 5162 - 1; isAlphabeticallyGreater(name, names[x]) && x >= 0; x--) {
					strcpy(names[x + 1], names[x]);
				}

				strcpy(names[x + 1], name);

				firstIndex = -1;

				// analysis
				if (nameLen > largestNameChar) {
					largestNameChar = nameLen;
				}

				namesCount++;
			}
		}
	}

	// now calculate name scores
	int runningSum = 0;
	
	for (int i = 0; i < 5163; i++) {
		int worth = 0;

		//printf("\n %d name: %s worth:", i + 1, names[i]);

		for (int ch = 0; ch < strlen(names[i]); ch++) {
			worth += indexOfAlphabet(names[i][ch]) + 1;
			//printf("%d + ", indexOfAlphabet(names[i][ch]) + 1);
		}

		int score = (i + 1) * worth;
		runningSum += score;
	}

	printf("\n analysis: [%d][%d]", namesCount, largestNameChar);

	printf("\n sum: %d", runningSum);

	fclose(file);
}
