// substring divisibility
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned int numFromDigits(int digits[], int len) {
	unsigned int num = 0;
	
	for (int i = 0; i < len; i++) {
		num += digits[i] * pow(10, len - i - 1);
	}

	return num;
}

int main() {
	long long unsigned int total = 0;

	for (int abc = 0; abc < 987; abc += 2) { // 987 for optimize because cannot have duplicate
		for (int d = 0; d <= 9; d++) {
			int bcd = ((abc % 100) * 10) + d;

			if (bcd % 3 == 0) {
				for (int e = 0; e <= 9; e++) {
					int cde = ((bcd % 100) * 10) + e;

					if (cde % 5 == 0) {
						for (int f = 0; f <= 9; f++) {
							int def = ((cde % 100) * 10) + f;

							if (def % 7 == 0) {
								for (int g = 0; g <= 9; g++) {
									int efg = ((def % 100) * 10) + g;

									if (efg % 11 == 0) {
										for (int h = 0; h <= 9; h++) {
											int fgh = ((efg % 100) * 10) + h;

											if (fgh % 13 == 0) {
												for (int i = 0; i <= 9; i++) {
													int ghi = ((fgh % 100) * 10) + i;

													if (ghi % 17 == 0) {
														int digits[10] = {-1};
														digits[1] = abc / 100;
														digits[2] = (abc / 10) % 10;
														digits[3] = abc % 10;

														digits[4] = d;
														digits[5] = e;
														digits[6] = f;

														digits[7] = g;
														digits[8] = h;
														digits[9] = i;

														bool hasDuplicates = false;
														int missingDigit = 0;
														for (int x = 1; x < 10; x++) {
															for (int y = 1; y < 10; y++) {
																if (digits[y] == digits[x] && y != x) {
																	hasDuplicates = true;
																}

																if (digits[y] == missingDigit) {
																	missingDigit++;
																}
															}
														}

														if (!hasDuplicates) {
															digits[0] = missingDigit;
															total += numFromDigits(digits, 10);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("%llu", total);
}
