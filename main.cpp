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

	if (!file.is_open()) { throw "Input file does not exist."; }

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
	
	std::cout << "Day " << day << std::endl;

	std::cout << "---------" << std::endl;

	switch (day) {
		case 1: result = day_one(input);
			break;
		case 2: result = day_two(input);
			break;
		case 3: result = day_three(input);
			break;
	}

	std::cout << "Part 1: " << result.part_one << "\n";
	std::cout << "Part 2: " << result.part_two << "\n";
}

void run_all_days() {
	for (int i = 1; i <= 25; i++) { 
		run_day(i); 
		std::cout << std::endl;
	}
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Error: Day number required\n";
		return 1;
	}

	if (std::string(argv[1]) == "--all") {
		run_all_days();
	} else {
		int day = atoi(argv[1]);
		
		try {
			run_day(day);
		} catch (const char* msg) {
			std::cerr << msg << std::endl;
		}
	}
	return 0;
}
