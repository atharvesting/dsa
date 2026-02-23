/*
@METADATA
Date: 2026-02-23
Problem: 1461. Check If a String Contains All Binary Codes of Size K
Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
Source: LeetCode (leetcode.com)
Pattern: Set, Bit Manipulation
Type: Solve
Publish: false

@JOURNEY
*/
#pragma once
#include <string>
#include <unordered_set>
using namespace std;
/*
@ITERATION_1
Method:
- Loop through all possible ordered substrings, and track unique ones in a set.
- If the number of elements in the set equal the number of required permutations, success.
*/
bool hasAllCodes1(string s, int k) {
    if (s.size() - k + 1 < (1 << k)) {
        return false;
    }
    int permute = 1 << k;  // Number of permutations of 0 and 1
    unordered_set<string> combo;
    for (int i = 0; i <= (int)s.size() - k; i++) {
        string t = s.substr(i, k);
        if (!combo.count(t)) {
            combo.insert(t);
        }
    }
    if (combo.size() == permute) {
        return true;
    }
    return false;
}
/*
@ITERATION_2
Method:
- Similar to Iteration 1 but with cleaner logic, type safety, and removed redundancies.
Complexity: O(n), Omega(1) if string contains one character.
*/
bool hasAllCodes2(string s, int k) {
    int permute = 1 << k;  // Number of permutations of 0 and 1
    if (s.size() < k) {
        return false;
    }
    unordered_set<string> combo;
    for (int i = 0; i <= (int)s.size() - k; i++) {
        combo.insert(s.substr(i, k));
    }
    if (combo.size() == permute) {
        return true;
    }
    return false;
}



