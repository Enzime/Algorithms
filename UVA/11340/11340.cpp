#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main() {
	int n;

	cin >> n;

	while (n--) {
		int k, m, v;
		char l;
		string line;
		map<char, int> worth;

		cin >> k;
		cin.ignore();

		while (k--) {
			getline(cin, line);
			stringstream magic(line);
			magic >> l;
			magic >> v;
			worth[l] = v;
		}

		cin >> m;
		cin.ignore();

		int total = 0;

		while (m--) {
			getline(cin, line);
			for (char c : line) {
				total += worth[c];
			}
		}

		string cents;
		stringstream magic;
		magic << total%100;
		magic >> cents;

		if (cents.length() == 1) {
			cents = "0" + cents;
		}

		cout << total/100 << "." << cents << "$" << endl;
	}
}
