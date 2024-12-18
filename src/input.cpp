#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <vector>

#include "execute.h"

/**
 * @brief Checks open parenthesis matches closing parenthesis
 * @param input The trimmed input string
 * @return Parenthesis are valid
 */
bool checkParenthesis(std::string input) {
    int balance = 0;
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (ch == '(') {
            if (i >= 1) {
                if (std::isdigit(input[i - 1]) || input[i - 1] == ')') {
                    return false;
                }
            }
            balance++;
        } else if (ch == ')') {
            balance--;
        }
        if (balance < 0) return false; // Closing parenthesis without matching opening
    }
    return balance == 0;
}


/**
 * @brief Checks validity of input
 * @param input The trimmed input string
 * @return Input is valid
 */
bool inputValid(const std::string &input) {
    std::string validOperators = "+-*/^";

    bool expectOperand = true; // Track if the next element is expected to be an operand
    bool firstCharInGroup = true; // Track if the first character in a group is an operand 
    // Check if the input has anything
    if (input.empty()) {
        throw std::invalid_argument("Empty input string");
    }
    for (char ch: input) {
        if (std::isdigit(ch)) {
            expectOperand = false;
            firstCharInGroup = false;
        } else if (validOperators.find(ch) != std::string::npos) {
            if (expectOperand) {
                if (ch == '-' && firstCharInGroup) { // allow negative numbers
                    firstCharInGroup = false;
                } else {
                    throw std::invalid_argument("Operator in invalid position");
                }
            }

            expectOperand = true;
        } else if (ch == '(') {
            // avoid implied multiplication
            if (!expectOperand) {
                throw std::invalid_argument("Invalid expression");
            }
            expectOperand = true; // After '(' we expect an operand
            firstCharInGroup = true;
        } else if (ch == ')') {
            if (expectOperand) {
                throw std::invalid_argument("Invalid parentheses");
            }
        } else {
            throw std::invalid_argument("Invalid character in input");
        }
    }
    if (expectOperand) {
        throw std::invalid_argument("Expression ends with an operator");
    }
    return checkParenthesis(input); // Ensure parentheses are balanced
}

/**
 * @brief Separates input into values and operators vectors
 * @param input The trimmed input string
 * @param values Empty vector for values of expression
 * @param operators Empty vector for operators of expression
 */
void separate(const std::string &input, std::vector<int> &values, std::vector<char> &operators) {
    std::string numBuffer;

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (std::isdigit(ch)) {
            // check if negative
            if (numBuffer.empty()) {
                // Might work to check fi negative , although will throw an exception before it gets here.
                if (i >= 2) {
                    if ((input[i - 1] == '-') && (std::string("+-*/^()").find(input[i - 2]) != std::string::npos)) {
                        operators.pop_back();
                        numBuffer += '-';
                    }
                } else if (i == 1) {
                    if (input[0] == '-') {
                        operators.pop_back();
                        numBuffer += '-';
                    }
                }
            }
            numBuffer += ch;
        } else {
            if (!numBuffer.empty()) {
                values.push_back(std::stoi(numBuffer));

                numBuffer.clear();
            }
            if (std::string("+-*/^()").find(ch) != std::string::npos) {
                operators.push_back(ch);
            }
        }
    }
    if (!numBuffer.empty()) {
        values.push_back(std::stoi(numBuffer));
    }
}

/**
 * @brief Dummy function for testing purposes only
 *
int execute(std::vector<int> &values, std::vector<char> &operators) {
    return 0;
}
*/

/**
 * @brief Initiates new expression input, called by calculator main class
 * @param input The input string
 *
 */
std::string newInput(std::string input, bool testFlag) {
    // Remove spaces from input
    std::string trimmedInput;
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (!std::isspace(ch)) {
            if (ch == '{' || ch == '[') ch = '(';
            else if (ch == '}' || ch == ']') ch = ')';

            trimmedInput += ch;
        }
    }

    try {
        // Validate input
        if (!inputValid(trimmedInput)) {
            throw std::invalid_argument("Invalid expression");
        }

        // Separate input into values and operators vectors
        std::vector<int> values;
        std::vector<char> operators;
        separate(trimmedInput, values, operators);

        // Print values and operators, for testing purposes only
        /*
        std::cout << "Values: ";
        for (int value: values) std::cout << value << " ";
        std::cout << std::endl;

        std::cout << "Operators: ";
        for (char i: operators) std::cout << i << " ";
        std::cout << std::endl;
        */
        // Call the execute function
        // TODO: Call the execution step
        int result = execute(values, operators);

        // turn result into string
        if (testFlag) {
            return std::to_string(result);
        }
        std::string resultString = "Result: " + std::to_string(result);
        return resultString;
    } catch (const std::exception &e) {
        std::string errorMessage = "Error: " + std::string(e.what());
        // std::cerr << errorMessage << std::endl;
        return errorMessage;
    }
}

/**
 * @brief Dummy main function, for testing purposes only
int main() {
    newInput();
    return 0;
}
*/

