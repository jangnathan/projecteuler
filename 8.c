#include <stdio.h>
#include <math.h>

const int n = 1000;

int main() {
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n - a; b++) {
			for (int c = 1; c <= n - a - b; c++) {
				if (a*a + b*b == c*c && a*a < b*b && b*b < c*c && a+b+c == 1000) {
					printf("%d %d %d \n", a, b, c);
					printf("%d", a * b * c);
				}
			}
		}
	}
}
