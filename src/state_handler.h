#ifndef STATE_HANDLER_H
#define STATE_HANDLER_H

#include <string>
#include "state.h"

#include "input_state.h"
#include "result_state.h"

class StateHandler {
private:
	State* currentState;

	InputState inputState;
	ResultState resultState;

public:
	StateHandler();

	// Set the current state
	void setState(string stateName, string arg = "");

	// Handle user input in the current state
	int input(string input);
};

#endif // STATE_HANDLER_H