#include "operators.h"
#include <cmath>
#include <stdexcept>

std::unordered_map<std::string, std::function<int(int, int)> > Operators::map = {
    {"+", Operators::add},
    {"-", Operators::subtract},
    {"*", Operators::multiply},
    {"/", Operators::divide},
    {"^", Operators::exponent},
};


bool Operators::is_operator(std::string op) {
    if (Operators::map.find(op) != Operators::map.end()) {
        return true;
    }
    return false;
}

int Operators::evaluate(std::string op, int a, int b) {
    // Function to add shorthand to evaluate operator.
    // The code should check to see if it is a valid operator by using
    // Operators::is_operator(operator)
    // Potential exception thrown: invalid_argument
    if (is_operator(op)) {
        return map.at(op)(a, b);
    }
    throw std::invalid_argument("Invalid operator");
}


int Operators::add(int a, int b) {
    return a + b;
}

int Operators::subtract(int a, int b) {
    return a - b;
}

int Operators::multiply(int a, int b) {
    return a * b;
}

int Operators::divide(int a, int b) {
    // As long as they are both int we are fine
    return a / b;
}

int Operators::exponent(int a, int b) {
    return pow(a, b);
}
