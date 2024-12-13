// STATE CLASS
// Represents a state where a certain user input will give you a certain output.

#ifndef STATE_H
#define STATE_H

#include <string>
#include <iostream>

class State {
private:
    std::string stateName; // Name/id of the state

public:
    State(const std::string& stateName) : stateName(stateName) {}
    virtual ~State() {}

    // Load the state. Called when the state is entered.
    virtual void load(std::string arg = "") {
        //std::cout << "[Loading state \"" << stateName << "\"]" << std::endl;
    }

    // Handle user input. Called after the state is loaded and when the user inputs something.
    virtual void input(std::string input) = 0;

    // Leave the state. Called when the state is switched away from.
    virtual void leave() {
        //std::cout << "[Leaving state \"" << stateName << "\"]" << std::endl;
    }

    // Get the name/id of the state
    std::string getStateName() {
        return stateName;
    }

    // Switch to a different state
    std::string switchToState;
    std::string switchToStateWith;
    void switchState(std::string stateName, std::string arg = "") {
        switchToState = stateName;
        switchToStateWith = arg;
    }
};

#endif // STATE_H