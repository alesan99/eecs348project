// STATE CLASS

// Represents a state where a certain user input will give you a certain output.

#include "state.h"
#include <iostream>

State::State(const string& stateName) : stateName(stateName) {}

void State::load(string arg) {
	cout << "[Loading state \"" << stateName << "\"]" <<  endl;
}

void State::input(string input) {}

void State::leave() {
	cout << "[Leaving state \"" << stateName << "\"]" <<  endl;
}


string State::getStateName() {
	return stateName;
}

void State::switchState(string stateName, string arg) {
	switchToState = stateName;
	switchToStateWith = arg;
}