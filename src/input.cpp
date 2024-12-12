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

        if (ch == '(') balance++;

        else if (ch == ')') balance--;

        if (balance < 0) return false; // Closing parenthesis without matching opening
    }

    return balance == 0; // True if all parentheses are balanced
}

/**
 * @brief Checks validity of input
 * @param input The trimmed input string
 * @return Input is valid
 */
bool inputValid(const std::string &input) {
    std::string validOperators = "+-*/^";

    bool expectOperand = true; // Track if the next element is expected to be an operand

    for (char ch: input) {
        if (std::isdigit(ch)) {
            expectOperand = false;
        } else if (validOperators.find(ch) != std::string::npos) {
            if (expectOperand) {
                throw std::invalid_argument("Operator in invalid position");
            }

            expectOperand = true;
        } else if (ch == '(') {
            expectOperand = true; // After '(' we expect an operand
        } else if (ch == ')') {
            if (expectOperand) {
                throw std::invalid_argument("Empty parentheses or invalid use of ')'");
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
std::string newInput(std::string input) {
    // Remove spaces from input
    std::string trimmedInput;
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (!std::isspace(ch)) {
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
        std::cout << "Values: ";
        for (int value: values) std::cout << value << " ";
        std::cout << std::endl;

        std::cout << "Operators: ";
        for (char i: operators) std::cout << i << " ";
        std::cout << std::endl;

        // Call the execute function
        // TODO: Call the execution step
        int result = execute(values, operators);

        // turn result into string
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

