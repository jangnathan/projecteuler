// integer right triangle
#include <stdio.h>
#include <math.h>

int main() {
	int pWithMostSolutions = 0;
	int mostSolutions = 0;
	for (int p = 12; p < 1000; p++) {
		int numSolutions = 0;
		for (int a = 0; a < p - 1; a++) {
			for (int b = a; b < p - 1; b++) {
				int c = p - a - b;
				float pythagoras = sqrt(pow(a, 2) + pow(b, 2));

				if (c == pythagoras) {
					numSolutions++;
				}
			}
		}

		if (numSolutions > mostSolutions) {
			pWithMostSolutions = p;
			mostSolutions = numSolutions;
		}
	}

	printf("%d", pWithMostSolutions);
}
