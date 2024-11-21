#ifndef RESULT_STATE_H
#define RESULT_STATE_H

#include <string>
#include "state.h"

class ResultState : public State {
public:
	ResultState() : State("result") {}

	void load(string result) {
		// Display result
		cout << "Result: " << result << endl;

		// Prompt user
		cout << "Do you want to input another expression? (Y/N):" << endl;
	}

	void input(string input) {
		// Decide what to do next
		if (input == "Y") { // Input another expression
			switchState("input");
		} else if (input == "N") { // Exit program
			cout << "Exiting..." << endl;
			exit(0);
		}
	}
};

#endif // RESULT_STATE_H