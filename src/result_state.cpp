#include "result_state.h"
#include <iostream>

ResultState::ResultState() : State("result") {}

void ResultState::load(string result) {
	// Display result
	cout << "Result: " << result << endl;

	// Prompt user
	cout << "Do you want to input another expression? (Y/N):" << endl;
}

void ResultState::input(string input) {
	// Decide what to do next
	if (input == "Y") { // Input another expression
		switchState("input");
	} else if (input == "N") { // Exit program
		cout << "Exiting program..." << endl;
		exit(0);
	}
}