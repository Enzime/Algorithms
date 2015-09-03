/*
Project Euler Problem 7
=======================

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
that the 6th prime is 13.

What is the 10001st prime number?
*/

#include <iostream>

using namespace std;

int main() {
	int primes[10001];
	int found = 1;
	bool notp = false;

	primes[0] = 2;

	for (int i = 3; found < 10001; i++) {
		notp = false;

		for (int j = 0; j < found; j++) {
			if (i % primes[j] == 0) {
				notp = true;
				break;
			}
		}

		if (notp) {
			continue;
		}

		primes[found++] = i;
	}

	cout << primes[found-1] << endl;
}
