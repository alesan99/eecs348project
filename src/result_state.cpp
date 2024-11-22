#include "result_state.h"
#include <iostream>

ResultState::ResultState() : State("result") {}

void ResultState::load(std::string result) {
	// Display result
	std::cout << "Result: " << result << std::endl;

	// Prompt user
	std::cout << "Do you want to input another expression? (Y/N):" << std::endl;
}

void ResultState::input(std::string input) {
	// Decide what to do next
	if (input == "Y") { // Input another expression
		switchState("input");
	} else if (input == "N") { // Exit program
		std::cout << "Exiting program..." << std::endl;
		exit(0);
	}
}