#include "state_handler.h"
#include <stdexcept>

StateHandler::StateHandler() : currentState(nullptr) {}

// Set the current state
void StateHandler::setState(string stateName, string arg) {
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
int StateHandler::input(string input) {
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