#include <iostream>
#include "minPairRemoveSortArray1.h"

int main() {
	std::vector<int> test = {5, 2, 3, 1};
	//int dvd = INT_MIN, dvs = -1;
	std::cout << "Answer iterations: " << minimumPairRemoval(test) << std::endl;

	/*for (int num : test) {
		std::cout << num << " ";
	}*/
	return 0;
}