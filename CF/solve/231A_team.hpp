/*
@METADATA
Date: 2026-10-10
Problem: 231A - Team
Link: https://codeforces.com/problemset/problem/231/A
Source: CF
Pattern: Greedy, Brute Force
Type: Solve
*/
#pragma once

#include <iostream>
#include <numeric>
#include <vector>


inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> v;
    v.reserve(n * 3);
    int tmp;
    for (int i = 0; i < n * 3; i++)
    {
        std::cin >> tmp;
        v.push_back(tmp);
    }
    int q{0};
    for (int i = 0; i < n * 3; i += 3)
    {
        if (std::accumulate(v.begin() + i, v.begin() + i + 3, 0) >= 2)
            q++;
    }
    std::cout << q;
}
