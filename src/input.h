#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

bool checkParenthesis(std::string input);

bool inputValid(std::string input);

void separate(const std::string &input, std::vector<int> &values, std::vector<char> &operators);

// Initiates new expression input
std::string newInput(std::string input);

#endif // INPUT_H
