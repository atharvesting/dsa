/*
@METADATA
Date: 2026-01-27
Problem: 20. Valid Paratheses
Link: https://leetcode.com/problems/valid-parentheses/
Source: LeetCode (leetcode.com)
Pattern: Stack
Type: Analyse
Publish: false

@GUIDELINES FOR ANALYSIS (Delete when analysis is completed)
- Liberally comment the solutions for understanding.
- Keep the broader implications of the solution in mind.
- Tinker with each solution to understand the significance of each element.

@PROBLEM STATEMENT
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/
#include <vector>
#include <string>
#include <stack>
/*
@SOLUTION_1_(BASIC/BRUTE_FORCE)
Complexity:
	Time: O(n^2), Ω(), Θ()
    find and erase are O(n) operations, and the main loop is O(n/2) worst case. O(n/2) * O(2n) = O(n^2)
	Space: O(n) -> find and erase function may create temporary copies, Ω() -> , Θ()
*/
bool brute_force(std::string s) {
    int n;
    do {
        // Track the current string length in every iteration for comparing later.
        n = s.length();  // Use .length() for strings, .size() for vectors
        size_t pos;  // size_t represents unsigned int values for size of objects
        /*
        * The string method .find() returns a size_t value, which is an unsigned int
        * While -1 can be used to indicate that a substring was not found,
        * string::npos is the safer way to perform the same membership check.
        * npos refers to the highest possible value size_t can take, which is system-dependent.
        * Returning the highest value effectively indicates that the value is not found.
        */
        if ((pos = s.find("()")) != std::string::npos) s.erase(pos, 2); 
        // erase(idx, n) deletes n characters starting from idx position
        else if ((pos = s.find("[]")) != std::string::npos) s.erase(pos, 2);
        // Each type of pair must be checked individually as the function does not allow group checks.
        else if ((pos = s.find("{}")) != std::string::npos) s.erase(pos, 2);
        /*
        * The core logic of this check lies in the fact that a there will be a time when a given
        * pair is found, given the string contains a valid parantheses pattern.
        * Once that pair is removed, it makes the recognition of previously divided pairs possible.
        */
    } while (s.length() < n);  // If the new length is not lesser than the previously tracked length, terminate.

    return s.empty();  // If empty, the pairs were valid. 1+ character(s) will be left if not.
}
/*
@SOLUTION_2_(ADVANCED/OPTIMAL)
Complexity:
	Time: O() -> , Ω() -> , Θ()
	Space: O() -> , Ω() -> , Θ()
Algorithm Applications: 
- 
- 
*/
bool optimal(std::string s) {
    std::stack<char> st;
    for (auto i : s) {
        if (i=='(' || i=='{' || i=='[') st.push(i);
        else {
            if (st.empty() || (st.top()=='(' && i!=')') || (st.top()=='{' && i!='}') || (st.top()=='[' && i!=']')) return false;
            st.pop();
        }
    }
    return st.empty();
}

/*
@TRADEOFFS
-

@LEARNINGS
- 
*/