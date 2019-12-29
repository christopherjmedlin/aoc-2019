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
	while (file.good()) {
		getline(file, line);
		lines.push_back(line);
	}

	file.close();
	return lines;
}

void run_day(int day) {
	int result = 0;
	std::vector<std::string> input = load_input(day);

	switch (day) {
		case 1:
			result = day_one();
	}

	std::cout << result << "\n";
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Error: Day number required\n";
		return 1;
	}
	int day = atoi(argv[1]);

	run_day(day);
}
