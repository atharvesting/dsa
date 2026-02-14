/*
@METADATA
Date: 2025-01-20
Problem: Evaluate Reverse Polish Notation (Difficulty: Medium)
Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
Source: LeetCode (leetcode.com)
Pattern: Stack
Publish: true

@JOURNEY
At first, my mind immediately went to using [i-1] and [i-2] indices to access the previous elements, but quickly,
that method failed to work. When I visited the Wikipedia page of RPN for some context for the problem, I came across
the crucial hint that a stack was necessary to properly handle the operands and the results.
I initially thought I needed a std::stack, but I haven't learned that header yet.
However, I knew how vectors worked, so I knew I could simulate stack behavior using a
vector's push_back and pop_back methods.

@ITERATION_FAILED
int evalRPN(std::vector<std::string>& tokens) {
    int opd1 = 0, opd2 = 0, result = 0;
    std::vector<int> bucket;
    for (const std::string str : tokens) {
        if (str == "+") {
            opd2 = bucket.back();
            bucket.pop_back();
            opd1 = bucket.back();
            bucket.pop_back();
            result = opd1 + opd2;
            bucket.push_back(result);
        } else bucket.push_back(std::stoi(str));
    }
    return result;
}
Method: 
- First, I implemented the logic for the plus sign only. It takes a string at a time.
- If it is the plus sign, then two numbers from the stack are popped, addition is done, and the 
result is pushed back to that stack.
- Else, the string is coverted into a number and pushed as well.
Why it failed: 
- The major problem with this program is that it lacks memory. It only works for the last operation done.
- In order to support multiple operations, I must store the result of the previous operations in the stack. I do
that, but in the end, I only return the value of result, which only stores the answer of the last operation done.
- Since the result is pushed back to the stack, then final answer will be found on top of the stack.

@ITERATION_SUCCESS
Method: 
- Proper simulation of stack behaviour using a vector, support for all operands, intermediate results pushed back to stack,
the value at the top of the stack is returned as the final result.
Complexity: O(n) time because each string is iterated through once, O(n) space because the stack may have to store almost all operands.

@LEARNINGS
- In C++, it is standard practice to use a reference to avoid 
unnecessary memory allocation and copying. Thus, `vector<string>& str` is used so that
the string is not copied.
- vector.back() --> Access last element of a vector.
- std::stoi(int num) --> Convert number in string type to integer type.
*/
#pragma once
#include <vector>
#include <string>
#include <iostream>

int evalRPN(std::vector<std::string>& tokens) {
    int opd1 = 0, opd2 = 0, result = 0;
    std::vector<int> bucket;
    for (const std::string& str : tokens) {
        // If the string represents an operator
        if ((str == "+") || (str == "-") || (str == "*") || (str == "/")) {
            opd2 = bucket.back(); bucket.pop_back();
            opd1 = bucket.back(); bucket.pop_back();

            if (str == "+") result = opd1 + opd2;
            else if (str == "-") result = opd1 - opd2;
            else if (str == "*") result = opd1 * opd2;
            else if (str == "/") result = opd1 / opd2;

            bucket.push_back(result);

        // If the string represents a number
        } else bucket.push_back(std::stoi(str)); 
    }
    return bucket.back(); // Since the result is pushed in the stack itself
}