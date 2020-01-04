#include "days.h"
#include "util/lines.h"

#include <algorithm>
#include <set>
#include <sstream>
#include <utility>

class Wire {
	std::vector<Line> vertical_lines;
	std::vector<Line> horizontal_lines;
	
public:
	using iterator = std::vector<Line>::iterator;
	Wire(std::string input);

	iterator vertical_begin() { return vertical_lines.begin(); }
	iterator vertical_end() { return vertical_lines.end(); }
	iterator horizontal_begin() { return horizontal_lines.begin(); }
	iterator horizontal_end() { return horizontal_lines.end(); }

	std::vector< std::pair<int, int> > intersections(Wire w);
};

Wire::Wire(std::string input) {
	
}

Answer day_three(std::vector<std::string> input) {
	return Answer {
		part_one: 0,
		part_two: 0
	};
}
