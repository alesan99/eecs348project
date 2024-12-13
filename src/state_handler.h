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
	void setState(std::string stateName, std::string arg = "");

	// Handle user input in the current state
	int input(std::string input);
};

#endif // STATE_HANDLER_H