#ifndef RESULT_STATE_H
#define RESULT_STATE_H

#include <string>
#include "state.h"

class ResultState : public State {
public:
	ResultState();

	void load(std::string result) override;
	void input(std::string input) override;
};

#endif // RESULT_STATE_H