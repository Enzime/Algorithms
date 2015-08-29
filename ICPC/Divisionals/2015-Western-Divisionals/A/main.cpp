#include <iostream>
#include <map>
#include <vector>
#include "Fraction.h"

using point = std::pair<Fraction, Fraction>;
using line = std::tuple<point, point, Fraction, Fraction>; // (x1,y1) (x2,y2) m c

int main() {
	std::map<point, std::vector<point>> graph;

	int x, y, n;

	// Read in x, y, n
	std::cin >> x >> y >> n;

	int x1, x2, y1, y2;
	point point1, point2;
	Fraction temp, m, c;

	std::vector<line> lines;

	for (int i = 0; i < n; i++) {
		// Read in (x1, y1) (x2, y2)
		std::cin >> x1 >> y1 >> x2 >> y2;

		// (x1, y1)
		point1 = {{x1, 1}, {y1, 1}};

		// (x2, y2)
		point2 = {{x2, 1}, {y2, 1}};

		// Add edges
		graph[point1].push_back(point2);
		graph[point2].push_back(point1);

		// calculate m and c
		m = {y2 - y1, x2 - x1};
		
		// create line
		lines.push_back(std::make_tuple(point1, point2, m, c));
	}

	for (int i = 0; i < lines.size(); i++) {
		int a, b, c;
		std::get<0>(lines[i]).first.get(a, b);
		std::get<0>(lines[i]).second.get(b, c);
		std::cout << a << " " << b << std::endl;
	}

	for (auto &iter : graph) {
		// iterate through points
		std::cout << iter.first.first.getFirst() << std::endl;
	}

	return 0;
}
