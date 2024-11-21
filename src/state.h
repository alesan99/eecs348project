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
	State(const string& stateName) : stateName(stateName) {}
	virtual ~State() {}
	
    // Load the state. Called when the state is entered.
	virtual void load(string arg = "") {
		cout << "[Loading state \"" << stateName << "\"]" <<  endl;
	}
    // Handle user input. Called after the state is loaded and when the user inputs something.
	virtual void input(string input) = 0;
    // Leave the state. Called when the state is switch away from.
	virtual void leave() {
		cout << "[Leaving state \"" << stateName << "\"]" <<  endl;
	}

    // Get the name/id of the state
	string getStateName() {
		return stateName;
	}

    // Switch to a different state
	string switchToState;
	string switchToStateWith;
	void switchState(string stateName, string arg = "") {
		switchToState = stateName;
		switchToStateWith = arg;
	}
};

#endif // STATE_H