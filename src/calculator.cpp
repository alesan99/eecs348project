#include <iostream>
#include <string>


#include "state_handler.h"

// Runs the input state with test argument, removing all user input and printing just the result.
void run_test_input(char **argv, StateHandler stateHandler) {
	stateHandler.setState("input", "test");
	std::string input = "-t " + std::string(argv[2]);
	stateHandler.input(input);
}


int main(int argc, char *argv[]) {
	StateHandler stateHandler;
	// Start on input state
	// Checks to see if the --test argument was passed.
	if (argc > 1) {
		if (std::string(argv[1]) == "--test") {
			run_test_input(argv, stateHandler);
			return 0;
		}
	}
	stateHandler.setState("input");
	// Input loop
	std::string input_str;
	while (true) {
		getline(std::cin, input_str);
		stateHandler.input(input_str);
	}
	return 0;
}

