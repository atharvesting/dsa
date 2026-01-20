/* 
def plusOne(self, digits: List[int]) -> List[int]:
    for i in range(len(digits) - 1, -1, -1):
        if digits[i] == 9:
            if i == 0:
                digits[i] = 0
                digits.insert(0, 1)
            else:
                digits[i] = 0
                digits[i - 1] += 1
        else:
            digits[i] += 1
            return digits

    return digits

vector<int> plusOne(vector<int>& digits) {
    int s = digits.size();
    for (int i = s - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        } else {
            if (i == 0) {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
            } else {
                digits[i - 1]++;
                digits[i] = 0;
            }
        }
        break;
    }
    return digits;
}

*/

#pragma once
#include <vector>

inline std::vector<int> plusOne(std::vector<int>& digits) {
	int s = digits.size();

	for (int i = s - 1; i >= 0; i--) {

		if (digits[i] < 9) {
			digits[i]++;
			return digits;
		}

		digits[i] = 0;
	}
	digits.insert(digits.begin(), 1);

	return digits;
}