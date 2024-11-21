#include "input_state.h"
#include <iostream>

InputState::InputState() : State("input") {}

void InputState::load(string arg) {
	cout << "Please input your expression:" << endl;
}

void InputState::input(string input) {
	expression = input;

	// TODO
	// 1. PARSE
	// 2. EVALUATE

	// Display result
	switchState("result", expression);
}