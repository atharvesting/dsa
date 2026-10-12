/*
@METADATA
Date: 2026-10-11
Problem: 158A - Next Round
Link: https://codeforces.com/problemset/problem/158/A
Source: CF
Pattern:
Type: Solve

@JOURNEY


@ITERATION_FAILED
Method:
Why:

@ITERATION_SUCCESS
Method:
Complexity:
Why:
*/
#pragma once
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n;
    std::cin >> k;
    std::vector<int> pos;
    pos.reserve(n);
    int tmp;

    for (int i = 0; i < n; i++)
    {
        std::cin >> tmp;
        pos.push_back(tmp);
    }
    tmp = 0;
    for (const auto& n : pos)
    {
        if (n > 0 && n >= pos[k - 1])
            tmp++;
    }
    std::cout << tmp;
}
