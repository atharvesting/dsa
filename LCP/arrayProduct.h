/*
@METADATA
Date:
Problem:
Link:
Source:
Pattern:
Type: Analyse
Publish: false

@GUIDELINES FOR ANALYSIS (Delete when analysis is completed)
- Liberally comment the solutions for understanding.
- Keep the broader implications of the solution in mind.
- Tinker with each solution to understand the significance of each element.

@PROBLEM STATEMENT


@INTUITION
- Initial Observations
- Pattern Indicators
*/
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
@SOLUTION_1_(BASIC/BRUTE_FORCE)
Complexity:
	Time: O() -> , Ω() -> , Θ()
	Space: O() -> , Ω() -> , Θ()
*/
vector<int> productExceptSelf1(vector<int>& nums) {
    int n = nums.size();
    vector<int> output;
    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            product *= nums[j];
        }
        output.push_back(product);
    }
    return output;
}
/*
@SOLUTION_3_(ADVANCED/OPTIMAL)
Complexity:
	Time: O(n) -> , Ω() -> , Θ()
	Space: O() -> , Ω() -> , Θ()
Algorithm Applications:
-
-
*/
vector<int> productExceptItself2(vector<int>& nums) {
 
    vector<int> prefix;
    int prod = 1;
    prefix.push_back(prod);
    for (int i = 1; i < nums.size(); i++) {
        prod *= nums[i - 1];
        prefix.push_back(prod);
    }

    prod = 1;
    vector<int> suffix(prefix.size(), 1);
    suffix[nums.size() - 1] = prod;
    for (int i = nums.size() - 2; i >= 0; i--) {
        prod *= nums[i + 1];
        suffix[i] = prod;
    }

    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        result.push_back(prefix[i] * suffix[i]);
    }

    return result;
}

/*
@TRADEOFFS
-

@LEARNINGS
-
*/