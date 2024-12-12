#include <iostream>
#include <string>
using namespace std;

#include "state_handler.h"

int main() {
	StateHandler stateHandler;

	// Start on input state
	stateHandler.setState("input");

	// Input loop
	string input_str;
	while (true) {
		getline(cin, input_str);
		stateHandler.input(input_str);
	}
	return 0;
}

