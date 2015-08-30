/*
Project Euler Problem 3
=======================

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?
*/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	long n = 600851475143, d = 3;

	while (n != 1) {
		if (n % d == 0) {
			n /= d;
		} else {
			d += 2;
		}
	}

	cout << d << endl;
}
