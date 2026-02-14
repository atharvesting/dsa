/*
@METADATA
Date: 2026-01-27
Problem: 20. Valid Paratheses
Link: https://leetcode.com/problems/valid-parentheses/
Source: LeetCode (leetcode.com)
Pattern: Stack
Type: Analyse
Publish: false

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
	Time: O(n) -> Single traversal needed, Ω(1) -> If the string is empty/contains closing bracket to begin with, Θ(n)
	Space: O(n) -> The stack stores n elements worst case (string only contains opening braces), Ω(1) -> Same reason as time omega, Θ(n)
Algorithm Applications: 
- Checking parentheses pairs in code editors.
- Recursion: Deepmost call goes at the top of the stack.
- Function calls: Most recent call goes at the top of the stack.
*/
bool optimal(std::string s) {
    std::stack<char> st;  // We track parentheses pairs using a stack, which only tracks opening brackets.
    for (auto i : s) {
        if (i=='(' || i=='{' || i=='[') st.push(i); // We push an opening bracket into the stack.
        else {
            /*
            * For the sake of clarity:
            *   - We reach this part when the character is not an opening bracket type! Which means that the next 
            *     character must be closing bracket. More specifically, it SHOULD complete the bracket type sitting at the
            *     top of the stack.
            *   - We are bound to encounter an adjacent pair of parentheses ('()', '[]', '{}') in a valid string.
            *
            * We are checking for a few options if the character is not an opening bracket:
            *   - If the stack is empty: This would mean that the string did not contain an opening bracket at the 
            *     beginning of the string, which immediately makes the string invalid.
            *   - If the next character in the string doesn't complete the bracket type at the top of the stack.
            *     For example, Stack = '([(', Next character = ']' --> Here, the next character does not complete the bracket
            *     at the top of the stack (rightmost element), which immediately makes the entire string invalid.
            */
            if (st.empty() || (st.top()=='(' && i!=')') || (st.top()=='{' && i!='}') || (st.top()=='[' && i!=']')) return false;
            
            st.pop(); // The top element is popped only after making sure that the corresponding opening bracket is available next.
        }
    }
    // If the string is valid, all opening bracket types will find their partners and thus, will all be popped out of the stack.
    // If the stack is not empty, it means that one of the opening brackets did not meet its corresponding closing one.
    return st.empty();
}

/*
@TRADEOFFS
- The brute force algorithm is intuitive as it exploits a crucial condition but has bad time complexity.
- The optimal algorithm uses extra space for the stack for better speed.

@LEARNINGS
- An essential problem-solving step is to recognise patterns, cases and conditions in the problem. 
    - Start with closing bracket --> Immediately invalid.
    - There must be at least one valid adjacent pair if the string is valid --> Main assumption.
*/