// counting sundays

#include <stdio.h>

int main() {
	int month = 1;
	int daysOfMonth = 1;
	int dayOfWeek = 1;
	int sundays = 0;

	for (int year = 1900; year < 2001;) {
		daysOfMonth++;

		if (month == 2) {
			if (year % 4 == 0) {
				if (daysOfMonth > 29) {
					daysOfMonth = 1;
					month++;
				}
			} else {
				if (daysOfMonth > 28) {
					daysOfMonth = 1;
					month++;
				}
			}
		} else {
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				if (daysOfMonth > 31) {
					daysOfMonth = 1;
					month++;
				}
			} else {
				if (daysOfMonth > 30) {
					daysOfMonth = 1;
					month++;
				}
			}
		}

		if (month > 12) {
			year++;
			month = 1;
		}

		dayOfWeek++;
		if (dayOfWeek > 7) {
			dayOfWeek = 1;
		}

		if (year > 1900) {
			if (daysOfMonth == 1) {
				if (dayOfWeek == 7) {
					sundays++;
				}
			}
		}
	}

	printf("%d", sundays);
}
