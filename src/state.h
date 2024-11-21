// STATE CLASS

// Represents a state where a certain user input will give you a certain output.

#ifndef STATE_H
#define STATE_H

#include <string>

class State {
private:
	std::string stateName; // Name/id of the state

public:
	State(const std::string& stateName);
	virtual ~State() {}

	// Load the state. Called when the state is entered.
	virtual void load(std::string arg = "");
	// Handle user input. Called after the state is loaded and when the user inputs something.
	virtual void input(std::string input) = 0;
	// Leave the state. Called when the state is switched away from.
	virtual void leave();

	// Get the name/id of the state
	std::string getStateName();

	// Switch to a different state
	std::string switchToState;
	std::string switchToStateWith;
	void switchState(std::string stateName, std::string arg = "");
};

#endif // STATE_H