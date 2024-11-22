#include <iostream>
#include "operators.h"

int main() {
	// Example use case
	int num1;
	int num2;
	char operation; {
		using namespace std;
		cout << "Enter number 1\n";
		cin >> num1;
		cout << "Enter operator\n";
		cin >> operation;
		cout << "Enter number 2\n";
		cin >> num2;
	}
	if (Operators::map.find(operation) != Operators::map.end()) {
		std::cout << Operators::map[operation](num1, num2);
	} else {
		std::cout << "Invalid operator";
		return -1;
	}
	return 0;
}

