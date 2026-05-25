// coin sums
// 2*4*10*20*40*100*200
#include <stdio.h>

// this is brute force 
int main() {
	int count = 0; // because of 2p
	float value = 0;
	for (int dollar = 0; dollar <= 2; dollar++) {
		value = 1.0 * dollar;
		if (value > 2.0)break;

		for (int fiftyp = 0; fiftyp <= 4; fiftyp++) {
			value = 1.0 * dollar + 0.50 * fiftyp;
			if (value > 2.0)break;

			for (int twentyp = 0; twentyp <= 10; twentyp++) {
				value = 1.0 * dollar + 0.50 * fiftyp + 0.10 * twentyp;
				if (value > 2.0)break;

				for(int tenp = 0; tenp <= 20; tenp++) {
					value = 1.0 * dollar + 0.50 * fiftyp + 0.10 * tenp + 0.05;
					if (value > 2.0)break;

					for (int fivep = 0; fivep <= 40; fivep++) {
						value = 1.0 * dollar + 0.50 * fiftyp + 0.10 * tenp + 0.05 * fivep;
						if (value > 2.0)break;

						for (int twop = 0; twop <= 100; twop++) {
							value = 1.0 * dollar + 0.50 * fiftyp + 0.10 * tenp + 0.05 * fivep + 0.02 *twop;
							if (value > 2.0)break;

							for (int onep = 0; onep <= 200; onep++) {
								value = (1.0*dollar) + (0.50*fiftyp) + (0.20*twentyp) + (0.10*tenp) + (0.05*fivep) + (0.02*twop) + (0.01*onep);

								if (value == 2.0) {
									count++;
								}
							}
						}
					}
				}
			}
		}
	}

	printf("%d", count);
}
