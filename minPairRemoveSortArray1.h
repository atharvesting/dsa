/*
@METADATA
Problem: 
Link: 
Source: 
Pattern: 
Publish: false

@JOURNEY
I initially thought I needed a std::stack, but I haven't learned that header yet.
I realized I could simulate the Last-In-First-Out (LIFO) behavior using a
vector's push_back and pop_back methods.

@ITERATION_FAILED
Method: 
Why: 

@ITERATION_SUCCESS
Method: 
Complexity: 
Why: 
*/
#pragma once
#include <vector>
#include <algorithm> // Necessary for using is_sorted()
#include <climits> // Necessary for using INT_MAX

int minimumPairRemoval(std::vector<int>& nums) {
    int i = 0, j = 1, iterr = 0, mini = INT_MAX;
    while (j < nums.size()) {

        if (std::is_sorted(nums.begin(), nums.end())) return iterr;
        else {
            i = 0; j = 1;
        }

        if (nums[i] + nums[j] < mini) {
            
            mini = nums[i] + nums[j];
            nums.erase(nums.begin() + i, nums.begin() + j + 1);
            i++; j++; iterr++;
            for (int n : nums) {
                std::cout << n << std::endl;
            }
        }

    }
    return iterr;
}