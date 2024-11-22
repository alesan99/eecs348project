#ifndef OPERATORS_H
#define OPERATORS_H
#include <functional>
#include <unordered_map>
// Use string so we can add more complex operators if ever needed
#include <string>

/*
 * Process for adding new operator:
 * 1: Declare it here in the header file
 * 2: Define it in the source file
 * 3: Add it to the map of functions (in the source file
*/

namespace Operators {
    // Unordered map of operator functions
    extern std::unordered_map<std::string, std::function<int(int, int)> > map;;

    // All supported operations.
    int add(int a, int b);

    int subtract(int a, int b);

    int multiply(int a, int b);

    int divide(int a, int b);

    int mod(int a, int b);

    int exponent(int a, int b);
};

#endif //OPERATORS_H
