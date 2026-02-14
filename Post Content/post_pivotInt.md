# Find the Pivot Integer

**Date:** 2025-01-20  
**Source:** [LeetCode](https://leetcode.com/problems/find-the-pivot-integer/description/)  
**Difficulty:** Easy  
**Pattern:** NA

---

## The Journey
As I approached this problem, my initial thought, as often happens, was to consider a brute-force solution. This would typically involve using nested loops to calculate the necessary sums for each potential pivot. However, before diving into that, I remembered the standard sum formula for numbers from 1 to `n`, which seemed perfectly suited for this particular challenge. Realizing this could lead to an O(n) solution, I decided to build my algorithm around it. My plan was to iterate through all numbers `x` from 1 to `n`. For each `x`, I would calculate the sum of numbers from 1 to `x` and the sum of numbers from `x` to `n` using the `(n * (n + 1)) / 2` formula. The sum from 1 to `x` is straightforward. For the sum from `x` to `n`, I envisioned calculating the total sum from 1 to `n` and then subtracting the sum from 1 to `x-1`. If these two calculated sums were equal, then `x` would be my pivot integer.

## The Failed Attempt
```cpp
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
```

**Why it failed:**
This attempt failed due to a subtle logical error in how I was calculating the sum of a range, specifically `Σ(i=x to n) i`. In my implementation, when trying to find `sum(x to n)`, I incorrectly used `sum(1 to n) - sum(1 to x)`. The issue here is that `x` itself is included in `sum(1 to x)`, which means I was effectively subtracting `x` twice or incorrectly removing it from the sum. The correct way to derive `sum(x to n)` from `sum(1 to n)` is to subtract `sum(1 to x-1)`: `sum(1 to n) = sum(1 to x-1) + sum(x to n)`. Therefore, `sum(x to n)` should correctly be `sum(1 to n) - sum(1 to x-1)`. This oversight led to incorrect range sum calculations and, consequently, an incorrect comparison for the pivot integer.

## The Solution
### Final Code
```cpp
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
```

**Why it works**
The final solution works because it rectifies the logical error in calculating the sum of a range that plagued my previous attempt. By adjusting the starting point `a` to `a-1` before calculating `sum_a` in the helper function `rs`, I correctly calculate `sum(1 to a-1)`, which then allows `sum_b - sum_a` to accurately represent `sum(a to b)`. This correction ensures that the range sum calculations are precise, making the comparison method for finding the pivot integer effective and reliable.

**Logic and Complexity:**
The method iterates through each number `i` from 1 to `n`. For each `i`, it calculates two sums: the sum of numbers from 1 to `i`, and the sum of numbers from `i` to `n`. These sums are efficiently computed using a helper function `rs` that leverages the arithmetic series sum formula `(k * (k + 1)) / 2`. The `rs(a, b)` function calculates the sum of integers from `a` to `b` by finding `sum(1 to b) - sum(1 to a-1)`. If the two sums are equal for any `i`, that `i` is the pivot integer and is returned. If no such integer is found after checking all possibilities, the function returns -1. This approach results in a time complexity of O(n) because the loop runs `n` times, and each sum calculation within the loop is an O(1) operation. The space complexity is O(1) as memory usage remains constant regardless of the input `n`.

## Learnings
This problem was a good reminder of the importance of precise range calculations, especially when dealing with arithmetic series formulas. I learned how a seemingly small logical oversight, like incorrectly handling the start or end points in a sum, can lead to incorrect results. It also reinforced the value of structuring helper functions effectively within a LeetCode problem, ensuring they perform their specific task accurately to support the main logic. My key takeaway is to always double-check the boundaries and inclusion/exclusion of terms when manipulating sums of ranges.