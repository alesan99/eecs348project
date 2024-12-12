#include "result_state.h"

#include <algorithm>
#include <iostream>

ResultState::ResultState() : State("result") {
}

void ResultState::load(std::string result) {
	// Check for -t flag (tests)
	if (result.length() > 3 && result.substr(0, 3) == "-t ") {
		result.erase(0, 3);
		std::cout << result << std::endl;
		return;
	}
	// Display result
	std::cout << result << std::endl;

	// Prompt user
	std::cout << "Do you want to input another expression? (Y/n):" << std::endl;
}

void ResultState::input(std::string input) {
	std::transform(input.begin(), input.end(), input.begin(), ::tolower); // case-insensitive
	// Decide what to do next
	std::string trimmedInput;
	for (int i = 0; i < input.length(); i++) {
		char ch = input[i];
		if (!std::isspace(ch)) {
			trimmedInput += ch;
		}
	}
	input = trimmedInput;
	if (input.length() == 0) {
		input = "y";
	}
	if (input == "y") {
		// Input another expression
		switchState("input");
	} else if (input == "n") {
		// Exit program
		std::cout << "Exiting program..." << std::endl;
		exit(0);
	} else {
		// Invalid input
		std::cout << "Invalid input. Please enter Y or n." << std::endl;
	}
}
