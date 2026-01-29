#include <iostream>
#include <vector>
#include "validParantheses.h"
#include <string>

int valid(std::string);

int main() {
	std::string test = "(())(){[]}}";
	std::cout << valid(test) << std::endl;

	return 0;
}

int valid(std::string test) {
	int og_len = test.length(), len_1, idx;
	do {
		len_1 = test.length();
		std::cout << "Current: " << len_1 << std::endl;
		if ((idx = test.find("()")) != std::string::npos) test.erase(idx, 2);
		if ((idx = test.find("[]")) != std::string::npos) test.erase(idx, 2);
		if ((idx = test.find("{}")) != std::string::npos) test.erase(idx, 2);

	} while (test.length() < len_1);

	return test.empty();
}