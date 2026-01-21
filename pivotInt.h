/*
@METADATA
Date: 2025-01-20
Problem: Find the Pivot Integer (Difficulty: Easy)
Link: https://leetcode.com/problems/find-the-pivot-integer/description/
Source: LeetCode (leetcode.com)
Pattern: NA
Publish: true

@JOURNEY
- As always, I thought of using brute force to solve the problem, where I would use nested loops to calculate the
required sums.
- Before I started with that approach, I remembered the sum formula for 1 to n, which would work perfectly for this 
problem and allow me to solve it in O(n) time. Thus I started with that and came up with this algorithm:

    Algorithm:
    - Iterate through all numbers x from 1 to n
    - For each x, calculate `Σ(i=1 to x) i` and `Σ(i=x to n) i` using the sum formula `(n * (n + 1)) / 2`
    - `Σ(i=1 to x) i` is straightforward. `Σ(i=x to n) i` will be equal to `(Σ(i=1 to n) i) - `(Σ(i=1 to x) i)`
    - If both are equal, return pivot number x.

@ITERATION_FAILED
int pivotInteger(int n) {
    for (int i = 1; i <= n; i++) {
        printf("1 to %d = %d, %d to %d = %d\n", i, rs(1, i), i, n, rs(i, n));
        if (rs(1, i) == rs(i, n)) return i;
    }
}
int rs(int a, int b) {
    // Finds sum of range a to b using (n * (n + 1)) / 2;
    if (a == 1) return (b * (b + 1)) / 2;

    int sum_a = (a * (a + 1)) / 2;
    std::cout << "Sum of " << a << " " << sum_a << std::endl;
    int sum_b = (b * (b + 1)) / 2;
    std::cout << "Sum of " << b << " " << sum_b << std::endl;
    return sum_b - sum_a;
}
Method: Use sum formula to solve the problem in linear time.
Why it failed: 
- A logical problem that seems simple in hindsight. 
- When calculating sum(1 to x) and sum(1 to n) to calculate sum(x to n), I was 
incorrectly including x in sum(1 to x), which is already included in the sum 
from sum(1 to n):

    sum(1 to n) = sum(1 to x-1) + sum(x to n) => sum(x to n) = sum(1 to n) - sum(1 to x-1)

@ITERATION_SUCCESS
Method: Same method but with the logical error fixed.
Complexity: O(n) time because operations don't scale with bigger numbers, O(1) space because memory use does not increase with scale.
Why: With the error fixed, the range sum calculations were carried out properly and the comparison method was effective.

@LEARNINGS
- How to properly structure helper functions in LeetCode problems.
*/
#pragma once
#include <vector>
#include <string>

int rs(int, int);

int pivotInteger(int n) {
    for (int i = 1; i <= n; i++) {
        // printf("1 to %d = %d, %d to %d = %d\n", i, rs(1, i), i, n, rs(i, n));
        if (rs(1, i) == rs(i, n)) return i;
    }
    return -1;
}

int rs(int a, int b) {
    // Finds sum of range a to b using (n * (n + 1)) / 2;

    a--;  // Correcting the range to calculate sum(a to b) properly
    int sum_a = (a * (a + 1)) / 2;
    int sum_b = (b * (b + 1)) / 2;
    return sum_b - sum_a;
}