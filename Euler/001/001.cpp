/*
Project Euler Problem 1
=======================

If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>

int main() {
	int sum = 0;
	bool added;

	for (int i=1;i<1000;i++) {
		added = false;

		if (i % 3 == 0) {
			sum += i;
			added = true;
		}

		if (i % 5 == 0 && !added) {
			sum += i;
		}
	}

	std::cout << sum << std::endl;

	return 0;
}
