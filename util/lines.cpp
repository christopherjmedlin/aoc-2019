#include "lines.h"
#include "bst.h"

#include <algorithm>
#include <iostream>

Line create_line(int x1, int y1, int x2, int y2) {
	Orientation axis;
	if (x1 == x2) { axis = vertical; }
	else if (y1 == y2) { axis = horizontal; }

	return Line {
		x1: std::min(x1, x2),
		y1: std::min(y1, y2),
		x2: std::max(x1, x2),
		y2: std::max(y1, y2),

		axis: axis
	};
}

// vertical line sweep - https://www.youtube.com/watch?v=dePDHVovJlE
std::vector< std::pair<int, int> > intersections(std::vector<Line> lines) {
	std::vector< std::pair<int, int> > intersects;
	std::vector< std::pair<int, Line*> > points;
	
	/*
		create vector of pairs in the form of (x-coord, line)
		such that the x coordinates can be iterated from left to right
		while also keeping references to the original line
	*/
	std::vector<Line>::iterator iter;
	for (iter = lines.begin(); iter < lines.end(); iter++) {
		// if vertical, only one x coord is needed
		points.push_back(std::make_pair(iter->x1, &(*iter)));
		if (iter->axis == horizontal) {
			points.push_back(std::make_pair(iter->x2, &(*iter)));
		}
	}
	// sort based on x coord
	std::sort(points.begin(), points.end());
	
	std::vector< std::pair<int, Line*> >::iterator piter;
	Node* bst = nullptr;
	for (piter = points.begin(); piter < points.end(); piter++) {
		if (piter->second->axis == horizontal) {
			// left point of horizontal line
			if (piter->first == piter->second->x1) {
				bst = bst_insert(piter->second->y1, bst);
			}
			// right point of horizontal line
			if (piter->first == piter->second->x2) {
			    bst = bst_remove(piter->second->y1, bst);
			}
		} else {
			// vertical line
			std::vector<int> y_intersection_vals;
			bst_range_search(&y_intersection_vals, 
							 piter->second->y1,
							 piter->second->y2,
							 bst);

			std::vector<int>::iterator i;
			for (i = y_intersection_vals.begin(); i < y_intersection_vals.end(); i++) {
				intersects.push_back(std::make_pair(piter->first, *i));		
			}
		}
	}

	return intersects;
}
