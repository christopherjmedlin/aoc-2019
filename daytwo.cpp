#include <sstream>
#include <array>

#include "days.h"

class IntcodeInterpreter {
	std::array<int, 150> mem;
	std::array<int, 150> rom;
	int pc;

public:
	IntcodeInterpreter(std::string program);

	void set_mem(int index, int val);
	int get_mem(int index);

	void run();
	void reset();
};

IntcodeInterpreter::IntcodeInterpreter(std::string program) {
	pc = 0;

	std::string num;
	std::istringstream iss { program };
	int count = 0;
	while (getline(iss, num, ',')) {
		rom[count] = std::stoi(num, nullptr, 10);
		count++;
	}
	mem = rom;
}

void IntcodeInterpreter::set_mem(int index, int val) { mem[index] = val; }
int IntcodeInterpreter::get_mem(int index) { return mem[index]; }

void IntcodeInterpreter::run() {
	while (mem[pc] != 99) {
		int addr1 = mem[pc + 1], addr2 = mem[pc + 2], output_addr = mem[pc + 3];
		switch (mem[pc]) {
			case 1: mem[output_addr] = mem[addr1] + mem[addr2];
				break;
			case 2: mem[output_addr] = mem[addr1] * mem[addr2];
				break;
		}
		pc += 4;
	}
}

void IntcodeInterpreter::reset() { mem = rom; pc = 0; }

Answer day_two(std::vector<std::string> input) {
	IntcodeInterpreter* intcode = new IntcodeInterpreter(input[0]);
	intcode->set_mem(1, 12);
	intcode->set_mem(2, 2);
	intcode->run();
	int part_one = intcode->get_mem(0);
	intcode->reset();
	
	int output = 0, noun, verb;
	bool found = false;
	for (noun = 0; noun <= 99; noun++) {
		for (verb = 0; verb <= 99; verb++) {
			intcode->set_mem(1, noun);
			intcode->set_mem(2, verb);
			intcode->run();
			if (intcode->get_mem(0) == 19690720) { found=true; break; }
			intcode->reset();
		}
		if (found) { break; }
	}

	return Answer {
		part_one: part_one,
		part_two: 100 * noun + verb
	};

	delete intcode;
}
