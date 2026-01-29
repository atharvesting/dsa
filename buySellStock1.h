/*
@METADATA
Date: 2026-01-26
Problem: 121. Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Source: LeetCode (leetcode.com)
Pattern: Dynamic Programming
Type: Analyse
Publish: false

@PROBLEM STATEMENT
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
#include <vector>
#include <algorithm>
#include <climits>
/*
@SOLUTION_1_(BASIC/BRUTE_FORCE)
Complexity:
	Time: O(n^2) -> Must traverse each element for each element, Ω(n^2) -> Must make all necessary comparisions, Θ(n^2) -> Avg is n^2
	Space: O(1) -> Only two variables used for processing, Ω(1) -> Array has two elements, Θ(n)
*/
int basic(std::vector<int>& prices) {
    int max_profit = 0;
    int n = prices.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  // Each element can only be compared with ones after it
            if (prices[j] - prices[i] > max_profit) {
                max_profit = prices[j] - prices[i];
            }
        }
    }
    return max_profit;
}

/*
@SOLUTION_2_(INTERMEDIATE)
Complexity:
	Time: O(n) -> Two loops iterate over n elements, Ω(n) -> Two loops are still executed, Θ(n)
	Space: O(n) -> Requires a helper array whose size is proportional to original, Ω(1) -> Array contains 2 elements, Θ(n)

*/
int intermediate(std::vector<int>& prices) {
    int n = prices.size();
    std::vector<int> maxPrices(n, 0);                               // Helper array of same size as OG and initialized with 0's
    maxPrices[n-1] = prices[n-1];                                   // Last values are synchronized
    for (int i=n-2; i>=0; i--) {
        maxPrices[i] = std::max(maxPrices[i+1], prices[i]); 
    }
    int maxProfit = 0;
    for (int i=0; i<n; i++) {
        maxProfit = std::max(maxProfit, maxPrices[i] - prices[i]); 
    }
    return maxProfit;
}


/*
@SOLUTION_3_(ADVANCED/OPTIMAL)
Complexity:
	Time: O(n) -> Only one loop needed, Ω(n) -> Single full loop necessary in best case as well, Θ()
	Space: O(1) -> Constanty space used, Ω(1) -> Same as worst case, Θ(1)
Algorithm Applications: 
- Ainancial Markets: Finding most profitable streak in a volatile market.
- Computer Vision: Can be used in maximum weight submatrix problems to detect bright spots.
*/
int optimal(std::vector<int>& prices) {
    int buy = prices[0];                            // Uses Kadane's algorithm
    int profit = 0;                                 
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < buy) {                      // Constant tracking for the lowest price point
            buy = prices[i];
        } else if (prices[i] - buy > profit) {
            profit = prices[i] - buy;
        }
    }
    return profit;
}

/*
@TRADEOFFS
- While solution 1 is simple, its time complexity makes it practically unusable.
- Solution 2 uses extra space to speed up the process.
- Solution 3 completes the task with linear time complexity while in constant space.

@LEARNINGS
- A greedy algorithm makes the best possible choice right now, and does not look back.
- 
*/