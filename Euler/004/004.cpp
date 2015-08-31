/*
Project Euler Problem 4
=======================

A palindromic number reads the same both ways. The largest palindrome made
from the product of two 2-digit numbers is 9009 = 91 * 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int largest;
	string num;
	int n;
	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			stringstream magic;
			n = i*j;
			if (n <= largest) {
				continue;
			}
			magic << n;
			magic >> num;

			bool palindrome = true;

			for (int k = 0; k < num.length(); k++) {
				if (num[k] != num[num.length()-1-k]) {
					palindrome = false;
				}
			}

			if (palindrome) {
				largest = n;
			}
		}
	}
	cout << largest << endl;
	return 0;
}
