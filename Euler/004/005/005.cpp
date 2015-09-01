/*
Project Euler Problem 5
=======================

2520 is the smallest number that can be divided by each of the numbers
from 1 to 10 without any remainder.

What is the smallest number that is evenly divisible by all of the numbers
from 1 to 20?
*/

#include <iostream>

using namespace std;

int main() {
	int i;
	bool cont;

	for (i = 2520;;i += 2520) {
		cont = false;
		for (int j = 11; j <= 20; j++) {
			if (i%j != 0) {
				cont = true;
				break;
			}
		}

		if (cont) {
			continue;
		}

		break;
	}

	cout << i << endl;
}
