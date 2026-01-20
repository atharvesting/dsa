#include <iostream>
#include "evaluateRPN.h"
#include <string>

int main() {
	std::vector<std::string> test = {"12", "4", "+", "4", "/"};
	std::cout << evalRPN(test) << std::endl;

	/*for (int num : test) {
		std::cout << num << " ";
	}*/
	return 0;
}