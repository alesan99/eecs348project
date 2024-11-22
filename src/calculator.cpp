#include <iostream>
#include "operators.h"

int main() {
	// Example use case
	int num1;
	int num2;
	std::string operation; {
		using namespace std;
		cout << "Enter number 1\n";
		cin >> num1;
		cout << "Enter operator\n";
		cin >> operation;
		cout << "Enter number 2\n";
		cin >> num2;
	}
	// Unsure if I want to go down the * Operators are strings * route.
	// This sort of operation would be needed each input, but it might be for the best?
	//std::string operation = std::string_from(char_operator)
	if (Operators::map.find(operation) != Operators::map.end()) {
		std::cout << Operators::map[operation](num1, num2) << std::endl;
	} else {
		std::cout << "Invalid operator";
		return -1;
	}
	return 0;
}

