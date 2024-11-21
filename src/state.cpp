// STATE CLASS

// Represents a state where a certain user input will give you a certain output.

#include "state.h"
#include <iostream>

State::State(const std::string& stateName) : stateName(stateName) {}

void State::load(std::string arg) {
	std::cout << "[Loading state \"" << stateName << "\"]" <<  std::endl;
}

void State::input(std::string input) {}

void State::leave() {
	std::cout << "[Leaving state \"" << stateName << "\"]" <<  std::endl;
}


std::string State::getStateName() {
	return stateName;
}

void State::switchState(std::string stateName, std::string arg) {
	switchToState = stateName;
	switchToStateWith = arg;
}