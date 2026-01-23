# Evaluate Reverse Polish Notation

**Date:** 2025-01-20  
**Source:** [LeetCode](https://leetcode.com/problems/evaluate-reverse-polish-notation/description/)  
**Difficulty:** Medium  
**Pattern:** Stack

---

## The Journey
Initially, my thoughts drifted towards using direct array indexing like `[i-1]` and `[i-2]` to access previous elements within the input array. However, this approach quickly proved inadequate for the dynamic nature of Reverse Polish Notation. Seeking a deeper understanding, I consulted the Wikipedia page for RPN, where I encountered the crucial insight that a stack data structure is essential for correctly managing operands and intermediate results. At the time, I hadn't yet familiarized myself with the `std::stack` header in C++. Nevertheless, I was confident in my knowledge of `std::vector` and realized I could effectively simulate the necessary stack behavior by utilizing its `push_back` and `pop_back` methods.

## The Failed Attempt
```cpp
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
```

**Why it failed:**
My initial attempt implemented logic only for the addition operator. It processed each string, popping two numbers from the simulated stack if it encountered a plus sign, performing the addition, and then pushing the result back. Otherwise, it converted the string to an integer and pushed it onto the stack. The primary flaw in this program was its lack of "memory" for the overall computation. It correctly processed individual operations and pushed their results back onto the stack. However, the function ultimately returned the `result` variable, which only stored the value of the *last* operation performed, rather than the accumulated final answer that was correctly residing at the top of the stack.

## The Solution
### Final Code
```cpp
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
```

**Why it works**
This solution effectively simulates the required stack behavior using a `std::vector`. It correctly identifies and handles all four basic arithmetic operators: addition, subtraction, multiplication, and division. When an operator is encountered, the two most recent operands are popped, the operation is performed, and the intermediate result is immediately pushed back onto the stack. This ensures that the stack continuously holds the necessary values for subsequent calculations. Crucially, the final answer is retrieved by returning the last element of the `bucket` vector, which represents the top of the stack after all operations have been processed.

**Logic and Complexity:**
The method involves iterating through each string in the input `tokens` vector. If a string represents an operand (a number), it is converted to an integer and pushed onto the `bucket` vector, which acts as our stack. If a string represents an operator, the top two elements are popped from the `bucket`, the corresponding arithmetic operation is performed, and the result is pushed back onto the `bucket`. After processing all tokens, the single remaining element at the top of the `bucket` (the last element of the vector) is the final result. This approach has a time complexity of O(n), where n is the number of tokens, because each token is processed exactly once. The space complexity is also O(n) in the worst case, as the `bucket` (stack) may need to store nearly all operands before operators begin reducing its size.

## Learnings
Through this problem, I reinforced several important C++ practices and concepts. I learned that it is standard practice to use a reference, such as `std::vector<std::string>& tokens`, to avoid unnecessary memory allocation and copying when passing large objects to functions. This improves efficiency by preventing the entire vector from being duplicated. Furthermore, I solidified my understanding of fundamental `std::vector` methods, specifically `vector.back()` for accessing the last element and `vector.pop_back()` for removing it. I also gained practical experience with `std::stoi()`, which is crucial for converting numeric strings into integer types, a common requirement in parsing problems.