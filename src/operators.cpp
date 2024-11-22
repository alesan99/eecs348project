#include "operators.h"
#include <cmath>

std::unordered_map<char, std::function<int(int, int)> > Operators::map = {
    {'+', Operators::add},
    {'-', Operators::subtract},
    {'*', Operators::multiply},
    {'/', Operators::divide},
    {'^', Operators::exponent},
};

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
