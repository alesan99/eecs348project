// STATE CLASS

// Represents a state where a certain user input will give you a certain output.

#ifndef STATE_H
#define STATE_H

#include <string>

using namespace std;

class State {
private:
	string stateName; // Name/id of the state

public:
	State(const string& stateName);
	virtual ~State() {}
	
	// Load the state. Called when the state is entered.
	virtual void load(string arg = "");
	// Handle user input. Called after the state is loaded and when the user inputs something.
	virtual void input(string input) = 0;
	// Leave the state. Called when the state is switched away from.
	virtual void leave();

	// Get the name/id of the state
	string getStateName();

	// Switch to a different state
	string switchToState;
	string switchToStateWith;
	void switchState(string stateName, string arg = "");
};

#endif // STATE_H