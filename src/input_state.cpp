#include "input_state.h"
#include <iostream>

InputState::InputState() : State("input") {}

void InputState::load(std::string arg) {
	std::cout << "Please input your expression:" << std::endl;
}

void InputState::input(std::string input) {
	expression = input;

	// TODO
	// 1. PARSE
	// 2. EVALUATE

	// Display result
	switchState("result", expression);
}