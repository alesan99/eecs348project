#ifndef INPUT_STATE_H
#define INPUT_STATE_H

#include <string>
#include "state.h"

class InputState : public State {
private:
	std::string expression;

public:
	InputState();

	void load(std::string arg = "") override;
	void input(std::string input) override;
};

#endif // INPUT_STATE_H