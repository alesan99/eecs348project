#include <string>
#include "state.h"

#include "input_state.h"
#include "result_state.h"

using namespace std;

class StateHandler {
private:
	State* currentState;

	InputState inputState;
	ResultState resultState;

public:
	// Constructor
	StateHandler() : currentState(nullptr) {}

	// Set the current state
	void setState(string stateName, string arg = "") {
		if (currentState) {
			currentState->leave();
		}

		 if (stateName == inputState.getStateName()) {
			currentState = &inputState;
		} else if (stateName == resultState.getStateName()) {
			currentState = &resultState;
		} else {
			throw invalid_argument("Unknown state: " + stateName);
		}

		currentState->load(arg);
	}

	// Handle the current state
	int input(string input) {
		if (currentState) {
			currentState->input(input);

			if (currentState->switchToState != "") {
				string targetState = currentState->switchToState;
				string targetStateWith = currentState->switchToStateWith;
				currentState->switchToState = "";
				currentState->switchToStateWith = "";
				setState(targetState, targetStateWith);
			}
		}
		return 0;
	}
};