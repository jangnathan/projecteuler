// distinct powers
#include <stdio.h>
#include <math.h>

typedef struct intCombo {
	unsigned int base;
	unsigned int exponent;
} intCombo;

int main() {
	intCombo intCombos[9801]; // 99 * 99 because of 2 - 100

	int count = 0;
	int index = 0;
	for (int x = 2; x <= 100; x++) {
		for (int y = 2; y <= 100; y++) {
			intCombo newIntCombo;
			newIntCombo.base = x;
			newIntCombo.exponent = y;

			double num = pow(newIntCombo.base, newIntCombo.exponent);
			intCombos[index] = newIntCombo;

			index++;
			count++;
			for (int i = 0; i < index - 1; i++) {
				double check = pow(intCombos[i].base, intCombos[i].exponent);
				if (num == check) {
					count--;
					break;
				}
			}
		}
	}

	printf("\n %d", count);
}
