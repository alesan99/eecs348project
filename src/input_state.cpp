#include "input_state.h"
#include <iostream>
#include <vector>
#include "input.h"
#include "execute.h"

InputState::InputState() : State("input") {
}

void InputState::load(std::string arg) {
	if (arg == "test") {
		return;
	}
	std::cout << "Please input your expression:" << std::endl;
}

void InputState::input(std::string input) {
	expression = input;
	bool test = false;
	std::string result = "";
	if (expression.length() > 3 && expression.substr(0, 3) == "-t ") {
		test = true;
		expression.erase(0, 3);
		result += "-t ";
	}
	result += newInput(expression, test);
	// PARSE and EVALUATE


	//result = std::to_string(execute(operands, operators));

	// Display result
	switchState("result", result);
}
