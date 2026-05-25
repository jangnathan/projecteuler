// factorial digit sum
// this is where i develop a better big int

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
	v->numDigits = 0;

	v->digits = malloc(sizeof(int) * v->maxDigits);
}

void vector_resize(bigInt *v, int maxDigits) {
    int *digits = realloc(v->digits, sizeof(int *) * maxDigits);
    if (digits) {
        v->digits = digits;
        v->maxDigits = maxDigits;
    }
}

void bigInt_addDigit(bigInt *v, int digit) {
	if (v->numDigits == v->maxDigits) {
		vector_resize(v, v->maxDigits * 2);
	}

	v->numDigits++;
	v->digits[v->numDigits] = digit; }

void bigInt_insert(bigInt *v, int digit) {
	if (v->numDigits == v->maxDigits) {
		vector_resize(v, v->maxDigits * 2);
	}

	for (int i = v->numDigits + 1; i >= 0; i--) {
		v->digits[i] = v->digits[i - 1];
	}

	v->numDigits++;
	v->digits[0] = digit;
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

int main() {
	bigInt number;
	int sum = 0;

	bigInt_init(&number, 1);

	number.digits[0] = 1;
	number.numDigits++;

	for (int i = 100; i > 0; i--) {
		bigInt_multiplyInt(&number, i);
	}

	for (int i = 0; i < number.numDigits; i++) {
		sum += number.digits[i];
	}
	printf("sum: %d \n digits:", sum);

	for (int i = 0; i < number.numDigits; i++) {
		printf("%d ", number.digits[i]);
	}

	free(number.digits);
}
