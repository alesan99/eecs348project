#include <iostream>
#include <string>
#include <cctype>


int checkParenthesis(std::string input) {
    int openParenthesis = 0;
    int closedParenthesis = 0;

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            openParenthesis++;
        }
        if (ch == ')' || ch == '}' || ch == ']') {
            closedParenthesis++;
        }
    }

    int validParenthesis = openParenthesis == closedParenthesis;

    return validParenthesis;
}

int checkInput(std::string input) {
    char lastChar = '\0'; // Initialize to null character
    int consecutiveCount = 0;

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (!std::isdigit(ch) && ch != '(' && ch != ')' && ch != '{' && ch != '}' && ch != '[' && ch != ']') {
            // Check if the current character is not a digit or any kind of bracket/parenthesis
            if (lastChar == ch) {
                consecutiveCount++;
                if (consecutiveCount >= 2) {
                    return 1; // Invalid input: 2+ consecutive non-digit characters
                }
            } else {
                consecutiveCount = 0; // Reset count if characters are not consecutive
            }
        } else {
            consecutiveCount = 0; // Reset count if the character is valid
        }
        lastChar = ch; // Update lastChar
    }

    return 0; // Input is valid
}

int main() {
    std::string input, result;
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Iterate through each character in the input string
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (!std::isspace(ch)) { // Check if the character is not whitespace
            result += ch; // Add non-whitespace characters to the result
        }
    }

    std::cout << "String without spaces or whitespace: " << result << std::endl;

    int validParenthesis = checkParenthesis(result);

    std::cout << "Parenthesis valid: " << validParenthesis << std::endl;

    int inputValid = checkInput(input);

    std::cout << "Valid operators: " << inputValid << std::endl;

    return 0;
}