#include "input_state.h"
#include <iostream>

#include "input.h"

InputState::InputState() : State("input") {}

void InputState::load(std::string arg) {
	std::cout << "Please input your expression:" << std::endl;
}

void InputState::input(std::string input) {
	expression = input;

	// PARSE and EVALUATE
	std::string result = newInput(expression);

	// Display result
	switchState("result", result);
}