/*
@METADATA
Date: 2026-10-11
Problem: 1903A - Halloumi Boxes
Link: https://codeforces.com/problemset/problem/1903/A
Source: CF
Pattern: Brute Force, Greedy
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

inline void solve() {
    int n{0}, k{0};
    std::cin >> n; std::cin >> k;
    int tmp;
    bool increasing = true, decreasing = true;
    std::vector<int> v;
    v.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> tmp;
        v[i] = tmp;
        if (i == 0) continue;
        if (v[i - 1] > v[i]) increasing = false;
        if (v[i - 1] < v[i]) decreasing = false;
    }
    if (k >= 2) std::cout << "YES\n";
    else if (increasing && decreasing) std::cout << "YES\n";
    else if (increasing) std::cout << "YES\n";
    else std::cout << "NO\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
