#pragma once
#include <vector>

inline int singleNumber(std::vector<int>& nums) {
	int s = nums.size();
	int result = 0;
	for (int num : nums) {
		/* We will use the Bitwise XOR operator
		here due to the following properties:
		
		n XOR 0 = n
		n XOR n = 0
		*/
		result ^= num;
	}
	return result;
}