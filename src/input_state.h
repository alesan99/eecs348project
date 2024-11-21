#ifndef INPUT_STATE_H
#define INPUT_STATE_H

#include <string>
#include "state.h"

using namespace std;

class InputState : public State {
private:
	string expression;

public:
	InputState(): State("input") {}

	void load(string arg = "") {
		cout << "Please input your expression:" << endl;
	}

	void input(string input) {
		expression = input;

		// TODO
		// 1. PARSE
		// 2. EVALUATE

		// Display result
		switchState("result", expression);
	}
};

#endif // INPUT_STATE_H