// prime permutations
#include "shorthand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void numToArray(u16 num, u8 *arr, u8 len) {
	// little endian
	// stores units at the start
	for (u8 i = 0; i < len; i++) {
		arr[i] = num % 10;
		num /= 10;
	}
}
u16 arrayToNum(u8 *arr, u8 len) {
	u16 num = 0;
	for (u8 i = 0; i < len; i++) {
		num *= 10;
		num += arr[i];
	}
	return num;
}
void arrayCpy(u8 *in, u8 *out, u8 offset, u8 len) {
	for (u8 i = 0; i < len; i++) {
		out[offset + i] = in[i];
	}
}

void reverse(u8 *in, u8 len) {
	for (u8 i = 0; i < (int)(len / 2); i++) {
		u8 temp = in[i];
		in[i] = in[len - i - 1];
		in[len - i - 1] = temp;
	}
}

// the next permutation is the next consecutive ones (smallest to largest)
// 123 -> 132 -> 213 -> 231 -> 312 -> 321 -> (reverse) 123
void nextU8Permutation(u8 *in, u8 len) {
	i16 pivot = -1;
	for (u8 i = 0; i < len - 1; i++) {
		// triggered on an increase
		if (in[i] < in[i + 1]) {
			pivot = i;
		}
	}
	if (pivot == -1) {
		reverse(in, len);
		return;
	}

	u8 next = 0;
	// assume it is in decreasing order
	for (u8 i = len - 1; i > pivot; i--) {
		if (in[i] > in[pivot]) {
			next = i;
			break;
		}
	}

	// swap next and pivot
	u8 temp = in[pivot];
	in[pivot] = in[next];
	in[next] = temp;

	reverse(in + pivot + 1, len - pivot - 1);
}

u8 isPrime(u16 num) {
	if (num < 2) return 0;
	if (num == 2) return 1;

	if (num % 2 == 0 || num % 3 == 0) return 0;

	for (u16 i = 5; i * i <= num; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) return 0;
	}

	return 1;
}

u8 tryNum(u16 n) {
	// 4! * 4
	u8 permutations[24 * 4];
	u8 original[4];
	numToArray(n, original, 4);

	for (u8 i = 0; i < 24; i++) {
		arrayCpy(original, permutations, i * 4, 4);
		nextU8Permutation(original, 4);
	}

	u16 nums[24]; // array of prime permutations
	u8 numLen = 0;
	for (u8 i = 0; i < 24; i++) {
		u16 num = arrayToNum(permutations + (i * 4), 4);
		if (num < 1000) continue;
		if (isPrime(num)) {
			nums[numLen] = num;
			numLen++;
		}
	}

	// find all increasing sequences with brute force O(n^3) (may be slow but amount of work is reduced by prime detect
	for (u8 x = 0; x < numLen - 2; x++) {
		for (u8 y = x + 1; y < numLen - 1; y++) {
			for (u8 z = y + 1; z < numLen; z++) {
				if (abs(nums[x] - nums[y]) == abs(nums[y] - nums[z]) && nums[x] != nums[z] && nums[x] > nums[y] && nums[y] > nums[z]) {
					printf("%d : %d : %d \n", nums[x], nums[y], nums[z]);
				}
			}
		}
	}

	return 0;
}

int main() {
	/*
	u16 ain = 1234;
	u8 aout[24 * 4];
	u8 a[4] = {1,2,3,4};
	numToArray(ain, a, 4);

	for (u8 i = 1; i < 24; i++) {
		nextU8Permutation(a, 4);
		arrayCpy(a, aout, i * 4, 4);
		printf("%d = %d %d %d %d\n", arrayToNum(a, 4), a[0], a[1], a[2], a[3]);
	}*/

	clock_t start, end;
	start = clock();
	for (u16 i = 1001; i < 10000; i += 6) {
		// 4! = 24
		if (tryNum(i) || tryNum(i + 2)) {
			break;
		}
	}
	end = clock();
	double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0f;
	printf("%.2f ms\n", time_taken);

	printf("find the number somewhere :)");
}
