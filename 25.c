// 1000 digit fibbonacci number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct bigInt {
	int *digits;
	int numDigits;
	int maxDigits;
} bigInt;

void bigInt_init(bigInt *v, int digits) {
	v->maxDigits = digits;
	v->numDigits = digits;

	v->digits = malloc(sizeof(int) * v->maxDigits);
}

void vector_resize(bigInt *v, int maxDigits) {
    int *digits = realloc(v->digits, sizeof(int) * maxDigits);
    if (digits) {
        v->digits = digits;
        v->maxDigits = maxDigits;
    }
}

void bigInt_print(bigInt v) {
	for (int i = 0; i < v.numDigits; i++) {
		printf("%d", v.digits[i]);
	}
}

void bigInt_addDigit(bigInt *v, int digit) {
	if (v->numDigits >= v->maxDigits) {
		vector_resize(v, v->maxDigits * 2);
	}

	v->digits[v->numDigits] = digit;
	v->numDigits++;
}

void bigInt_insert(bigInt *v, int digit) {
	if (v->numDigits >= v->maxDigits) {
		vector_resize(v, v->maxDigits * 2);
	}

	for (int i = v->numDigits + 1; i >= 0; i--) {
		v->digits[i] = v->digits[i - 1];
	}

	v->digits[0] = digit;
	v->numDigits++;
}

void bigInt_multiplyInt(bigInt *v, int multiplier) {
	for (int i = 0; i < v->numDigits; i++) {
		v->digits[i] = v->digits[i] * multiplier;

		// turns em into digits
		for (int x = i; x >= 0; x--) {
			if (v->digits[x] > 9) {
				if (x < 1) {
					bigInt_insert(v, v->digits[x] / 10);
					v->digits[x + 1] = v->digits[x + 1] % 10;
					i++;
					x++;
				} else {
					v->digits[x - 1] += v->digits[x] / 10;
					v->digits[x] = v->digits[x] % 10;
				}
			}
		}
	}
}

void bigInt_addBigInt(bigInt *v, bigInt add) {
	for (int i = 0; i < add.numDigits; i++) {
		if (v->numDigits - i <= 0) {
			bigInt_insert(v, add.digits[add.numDigits - i - 1]);
			i++;
		} else {
			v->digits[(v->numDigits - i) - 1] += add.digits[(add.numDigits - i) - 1];
		}

		for (int x = v->numDigits - i - 1; x >= 0; x--) {
			if (v->digits[x] > 9) {
				if (x < 1) {
					bigInt_insert(v, v->digits[x] / 10);
					v->digits[x + 1] = v->digits[x + 1] % 10;
					x++;
				} else {
					v->digits[x - 1] += v->digits[x] / 10;
					v->digits[x] = v->digits[x] % 10;
				}
			}
		}
	}
}

void bigInt_clear(bigInt *v) {
	for (int i = 0; i < v->numDigits; i++) {
		v->digits[i] = 0;
	}
}

void bigInt_setToBigInt(bigInt *v, bigInt set) {
	bigInt_clear(v);
	v->numDigits = 0;

	for (int i = 0; i < set.numDigits; i++) {
		bigInt_addDigit(v, set.digits[i]);
	}
}

int main() {
	bigInt currentNumber;
	bigInt_init(&currentNumber, 1);
	currentNumber.digits[0] = 0;

	bigInt prevNumber;
	bigInt_init(&prevNumber, 1);
	prevNumber.digits[0] = 0;

	bigInt secondPrevNumber;
	bigInt_init(&secondPrevNumber, 1);
	secondPrevNumber.digits[0] = 1;

	int i = 0;

	while (currentNumber.numDigits != 1000 - 1) { // for some reason project euler is weird so you put 999
		i++;
		if (i < 10) {
			printf("\n");
			bigInt_print(currentNumber);
			printf(" index: %d digits: %d", i, currentNumber.numDigits);
		}
		bigInt_clear(&currentNumber);
		bigInt_addBigInt(&currentNumber, prevNumber);
		bigInt_addBigInt(&currentNumber, secondPrevNumber);
		bigInt_setToBigInt(&secondPrevNumber, prevNumber);
		bigInt_setToBigInt(&prevNumber, currentNumber);
	}

	printf("\n");
	bigInt_print(currentNumber);
	printf("\nindex: %d digits: %d", i, currentNumber.numDigits);

	free(currentNumber.digits);
	free(prevNumber.digits);
	free(secondPrevNumber.digits);
}
