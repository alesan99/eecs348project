//
// Created by disco on 11/21/2024.
//

#ifndef OPERATORS_H
#define OPERATORS_H
#include <functional>
#include <unordered_map>
#include <string>

/*
 * Process for adding new operator:
 * 1: Declare it here in the header file
 * 2: Define it in the source file
 * 3: Add it to the map of functions (in the source file
*/

namespace Operators {
    int add(int a, int b);

    // Unordered map of functions.
    extern std::unordered_map<char, std::function<int(int, int)> > map;;

    int subtract(int a, int b);

    int multiply(int a, int b);

    int divide(int a, int b);

    int mod(int a, int b);

    int exponent(int a, int b);
};

#endif //OPERATORS_H
