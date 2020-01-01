#include "days.h"

#include <algorithm>
#include <set>
#include <sstream>
#include <utility>

/*
 * For this day I used a vertical line sweep algorithm:
 * https://www.youtube.com/watch?v=dePDHVovJlE
 *
 * This assumes that each point where the wires change direction is completely
 * unique. Even if this isn't the case, the possibility of the degenerate
 * case also happening to be the closest point of intersection is unlikely.
 */

enum Orientation { vertical, horizontal };

struct Line {
	int x1;
	int y1;
	int x2;
	int y2;
	Orientation axis;
};

Line create_line(int x1, int y1, int x2, int y2, Orientation axis) {
	return Line {
		x1: std::min(x1, x2),
		y1: std::min(y1, y2),
		x2: std::max(x1, x2),
		y2: std::max(y1, y2),

		axis: axis
	};
}

class Wire {
	// vertical and horizontal are seperated because when we compare
	// wires we only want to compare the horizontal lines of one with the
	// vertical of the other and vice versa
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
