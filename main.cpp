#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <stdlib.h>

#include "days.h"

std::vector<std::string> load_input(int day) {

	std::string input_path = "inputs/day" + std::to_string(day) + ".txt";
	std::ifstream file;

	std::string line;
	std::vector<std::string> lines;
	file.open(input_path, std::ifstream::in);
	while (!file.eof()) {
		getline(file, line);
		lines.push_back(line);
	}
	lines.pop_back();

	file.close();
	return lines;
}

void run_day(int day) {
	Answer result;
	std::vector<std::string> input = load_input(day);

	switch (day) {
		case 1:
			result = day_one(input);
	}

	std::cout << "Part 1: " << result.part_one << "\n";
	std::cout << "Part 2: " << result.part_two << "\n";
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Error: Day number required\n";
		return 1;
	}
	int day = atoi(argv[1]);

	run_day(day);
}
